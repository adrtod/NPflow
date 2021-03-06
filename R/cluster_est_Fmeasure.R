#'Gets a point estimate of the partition using the F-measure as the cost function
#'
#'@param c a list of vector of length \code{n}. \code{c[[j]][i]} is 
#'the cluster allocation of observation \code{i=1...n} at iteration 
#'\code{j=1...N}.
#'
#'@param logposterior vector of logposterior correponding to each 
#'partition from \code{c} used to break ties when minimizing the cost function
#'
#'@return a \code{list}: 
#'  \itemize{
#'      \item{\code{c_est}:}{ a vector of length \code{n}. Point estimate of the partition}
#'      \item{\code{cost}:}{ a vector of length \code{N}. \code{cost[j]} is the cost 
#'      associated to partition \code{c[[j]]}}
#'      \item{\code{similarity}:}{  matrix of size \code{n x n}. Similarity matrix 
#'      (see \link{similarityMat})}
#'      \item{\code{opt_ind}:}{ the index of the optimal partition 
#'      among the MCMC iterations.}  
#'  }
#'
#'
#'@author Francois Caron, Boris Hejblum
#'
#'@export
#'
#'@references F. Caron, Y.W. Teh, T.B. Murphy. Bayesian nonparametric Plackett-Luce 
#' models for the analysis of preferences for college degree programmes. 
#' To appear in Annals of Applied Statistics, 2014.
#' http://arxiv.org/abs/1211.5037
#' 
#' D. B. Dahl. Model-Based Clustering for Expression Data via a 
#' Dirichlet Process Mixture Model, in Bayesian Inference for 
#' Gene Expression and Proteomics, K.-A. Do, P. Muller, M. Vannucci 
#' (Eds.), Cambridge University Press, 2006.
#'
#'@seealso \link{similarityMat}
#'

cluster_est_Fmeasure <- function(c, logposterior){
    #    n <- length(c[[1]])
    
    #    N <- length(c)
    
    
    #     #Non vectorized piece of code for reference
    #         cost <- numeric(N)
    #         similarity <- matrix(ncol=n, nrow=n)
    #         for(i in 1:(n-1)){
    #              for(j in (i+1):n){
    #                  similarity[i,j] <- 1/N*sum(unlist(lapply(c, "[", i)) == unlist(lapply(c, "[", j)))
    #                  #cost = cost + abs(as.numeric(unlist(lapply(c, "[",i))==unlist(lapply(c, "[",j)))-similarity[i,j])
    #                  for(k in 1:N){
    #                      cost[k] = cost[k] + abs(as.numeric(c[[k]][i]==c[[k]][j]) - similarity[i,j])
    #                  }
    #             }
    #         }
    #         cost <- 2*cost
    
    #    #Fully vectorized code uses too much live memory :-(
    #     vclust2mcoclust <- function(v){
    #         m <- sapply(v, FUN=function(x){v==x})
    #         return(m)
    #     }
    #     list_mcoclust <- lapply(c, vclust2mcoclust)
    #     
    #     similarity <- Reduce('+', list_mcoclust)/N
    #     list_cost <- lapply(list_mcoclust, function(m){abs(m-similarity)})
    #     cost <- unlist(lapply(list_cost, sum))
    
    #     #Best R implementation 
    #         cost <- numeric(N)
    #         vclust2mcoclust <- function(v){
    #             m <- sapply(v, FUN=function(x){v==x})
    #             return(m)
    #         }
    #         cat("Estimating posterior similarity matrix...\n(this may take some time, complexity in O(n^2))\n")
    #         similarity <- matrix(0, ncol=n, nrow=n)
    #         for (i in 1:N){
    #             similarity <- similarity + vclust2mcoclust(c[[i]])
    #         }
    #         similarity <- similarity/N
    #         cat("DONE!\n")
    #         cat("Estimating cost of MCMC partitions...\n(this may take some time, complexity in O(n^2))\n")
    #         for (i in 1:N){
    #             cost[i] <- sum(abs(vclust2mcoclust(c[[i]])-similarity))
    #         }
    #         
    cat("Estimating posterior F-measures matrix...\n(this may take some time, complexity in O(n^2))\n")
    cmat <- sapply(c, "[")
    tempC <- Fmeasure_costC(cmat)
    cat("DONE!\n")
    
    Fmeas <- tempC$Fmeas
    cost <- tempC$cost
    
    
    opt_ind <- which(cost==min(cost)) #not use which.min because we want the MCMC iteration maximizing logposterior in case of ties
    if(length(opt_ind)>1){
        opt_ind <- opt_ind[which.max(logposterior[opt_ind])]
    }
    c_est <- c[[opt_ind]]
    
    return(list("c_est"=c_est, "cost"=cost, "Fmeas"=Fmeas, "opt_ind"=opt_ind))
}