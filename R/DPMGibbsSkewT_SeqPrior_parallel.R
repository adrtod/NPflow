#'Slice Sampling of Dirichlet Process Mixture of skew  Students's t-distibutions
#'
#'@param z data matrix \code{d x n} with \code{d} dimensions in rows 
#'and \code{n} observations in columns.
#'
#'@param hyperG0 prior mixing distribution.
#'
#'@param a shape hyperparameter of the Gamma prior 
#'on the parameter of the Dirichlet Process.
#'
#'@param b scale hyperparameter of the Gamma prior 
#'on the parameter of the Dirichlet Process.
#'
#'@param N number of MCMC iterations.
#'
#'@param doPlot logical flag indicating wether to plot MCMC iteration or not.
#'Default to \code{TRUE}.
#'
#'@param nbclust_init number of clusters at initialisation. 
#'Default to 30 (or less if there are less than 30 observations).
#'
#'@param verbose logical flag indicating wether partition info is 
#'written in the console at each MCMC iteration.
#'
#'@return a object of class \code{DPMclust} with the following attributes: 
#'  \itemize{
#'      \item{\code{mcmc_partitions}:}{a list of length \code{N}. Each
#'       element \code{mcmc_partitions[n]} is a vector of length 
#'       \code{n} giving the partition of the \code{n} observations.}
#'      \item{\code{alpha}:}{ a vector of length \code{N}. \code{cost[j]} is the cost 
#' associated to partition \code{c[[j]]}}
#'      \item{\code{weights_list}:}{}
#'      \item{\code{logposterior_list}:}{}
#'      \item{\code{data}:}{the data matrix \code{d x n} with \code{d} dimensions in rows 
#'and \code{n} observations in columns.}
#'      \item{\code{nb_mcmcit}:}{the number of MCMC itertations}
#'  }
#'
#'@author Boris Hejblum
#'
#'@export
#'
#'@examples
#' rm(list=ls())
#' library(ggplot2)
#' 
#' #Number of data
#' n <- 2000
#' set.seed(123)
#' #set.seed(4321)
#' 
#' 
#' d <- 2
#' ncl <- 4
#' 
#' # Sample data
#' 
#' sdev <- array(dim=c(d,d,ncl))
#' 
#' #xi <- matrix(nrow=d, ncol=ncl, c(-1.5, 1.5, 1.5, 1.5, 2, -2.5, -2.5, -3))
#' #psi <- matrix(nrow=d, ncol=4, c(0.4, -0.6, 0.8, 0, 0.3, -0.7, -0.3, -0.8))
#' xi <- matrix(nrow=d, ncol=ncl, c(-0.2, 0.5, 2.4, 0.4, 0.6, -1.3, -0.9, -2.7))
#' psi <- matrix(nrow=d, ncol=4, c(0.3, -0.7, -0.8, 0, 0.3, -0.7, 0.2, 0.9))
#' nu <- c(100,15,8,5)
#' p <- c(0.15, 0.05, 0.5, 0.3) # frequence des clusters
#' sdev[, ,1] <- matrix(nrow=d, ncol=d, c(0.3, 0, 0, 0.3))
#' sdev[, ,2] <- matrix(nrow=d, ncol=d, c(0.1, 0, 0, 0.3))
#' sdev[, ,3] <- matrix(nrow=d, ncol=d, c(0.3, 0.15, 0.15, 0.3))
#' sdev[, ,4] <- .3*diag(2)
#' 
#'  
#' c <- rep(0,n)
#' w <- rep(1,n)
#' z <- matrix(0, nrow=d, ncol=n)
#' for(k in 1:n){
#'  c[k] = which(rmultinom(n=1, size=1, prob=p)!=0)
#'  w[k] <- rgamma(1, shape=nu[c[k]]/2, rate=nu[c[k]]/2)
#'  z[,k] <- xi[, c[k]] + psi[, c[k]]*rtruncnorm(n=1, a=0, b=Inf, mean=0, sd=1/sqrt(w[k])) + (sdev[, , c[k]]/sqrt(w[k]))%*%matrix(rnorm(d, mean = 0, sd = 1), nrow=d, ncol=1)
#'  cat(k, "/", n, " observations simulated\n", sep="")
#' }
#'  
#' # Set parameters of G0
#' hyperG0 <- list()
#' hyperG0[["b_xi"]] <- rowMeans(z)
#' hyperG0[["b_psi"]] <- rep(0,d)
#' hyperG0[["kappa"]] <- 0.001
#' hyperG0[["D_xi"]] <- 100
#' hyperG0[["D_psi"]] <- 100
#' hyperG0[["nu"]] <- d+1
#' hyperG0[["lambda"]] <- diag(apply(z,MARGIN=1, FUN=var))/3
#'  
#'  # hyperprior on the Scale parameter of DPM
#'  a <- 0.0001
#'  b <- 0.0001
#'  
#'  # do some plots
#'  nbclust_init <- 30
#'  
#'  ## Plot Data
#'  q <- (ggplot(data.frame("X"=z[1,], "Y"=z[2,]), aes(x=X, y=Y)) 
#'        + geom_point()
#'        + ggtitle("Simple example in 2d data")
#'        +xlab("D1")
#'        +ylab("D2")
#'        +theme_bw())
#'  q
#'  
#'  MCMCsample_st <- DPMGibbsSkewT(z, hyperG0, a, b, N=3000, 
#'                                 doPlot=TRUE, plotevery=250,
#'                                 nbclust_init, diagVar=FALSE)
#'  s <- summary(MCMCsample_st, burnin = 2000, thin=5, posterior_approx=TRUE)
#'  F <- FmeasureC(pred=s$point_estim$c_est, ref=c)
#'  
#' for(k in 1:n){
#'  c[k] = which(rmultinom(n=1, size=1, prob=p)!=0)
#'  w[k] <- rgamma(1, shape=nu[c[k]]/2, rate=nu[c[k]]/2)
#'  z[,k] <- xi[, c[k]] + psi[, c[k]]*rtruncnorm(n=1, a=0, b=Inf, mean=0, sd=1/sqrt(w[k])) + (sdev[, , c[k]]/sqrt(w[k]))%*%matrix(rnorm(d, mean = 0, sd = 1), nrow=d, ncol=1)
#'  cat(k, "/", n, " observations simulated\n", sep="")
#' }
#'  MCMCsample_st2 <- DPMGibbsSkewT_SeqPrior_parallel(Ncpus=2, type_connec="SOCK", 
#'                                                    z, prior=s$param_posterior, 
#'                                                    hyperG0, N=3000, 
#'                                                    doPlot=TRUE, plotevery=100,
#'                                                    nbclust_init, diagVar=FALSE, verbose=FALSE)
#' s2 <- summary(MCMCsample_st2, burnin = 2000, thin=5)
#' F2 <- FmeasureC(pred=s2$point_estim$c_est, ref=c)
#'  
#'  
#'  

DPMGibbsSkewT_SeqPrior_parallel <- function (Ncpus, type_connec,
                                             z, prior, hyperG0, N, nbclust_init,
                                             doPlot=TRUE, plotevery=1, 
                                             diagVar=TRUE, verbose=TRUE,
                                             monitorfile="defaultmonitor.txt",
                                             ...){
    
    # declare the cores
    library(doSNOW)
    cl <- makeCluster(Ncpus, type = type_connec)
    registerDoSNOW(cl)
    
    if(doPlot){library(ggplot2)}
    
    p <- dim(z)[1]
    n <- dim(z)[2]
    U_xi <- matrix(0, nrow=p, ncol=n)
    U_psi <- matrix(0, nrow=p, ncol=n)
    U_Sigma <- array(0, dim=c(p, p, n))
    U_df <- rep(10,n)
    U_B <- array(0, dim=c(2, 2, n))
    U_nu <- rep(p,n)
    
    par_ind <- list()
    temp_ind <- 0
    if(Ncpus>1){
        nb_simult <- floor(n%/%(Ncpus))
        for(i in 1:(Ncpus-1)){
            par_ind[[i]] <- temp_ind + 1:nb_simult
            temp_ind <- temp_ind + nb_simult
        }
        par_ind[[Ncpus]] <- (temp_ind+1):n
    }
    else{
        cat("Only 1 core specified\n=> non-parallel version of the algorithm would be more efficient")
        cat("Only 1 core specified\n=> non-parallel version of the algorithm would be more efficient",
            file=monitorfile, append = TRUE)
        nb_simult <- n
        par_ind[[Ncpus]] <- (temp_ind+1):n
    }
    
    # U_SS is a list where each U_SS[[k]] contains the sufficient
    # statistics associated to cluster k
    U_SS <- list()
    
    #store U_SS :
    U_SS_list <- list()
    #store clustering :
    c_list <- list()
    #store sliced weights
    weights_list <- list()
    
    #store log posterior probability
    logposterior_list <- list()
    
    m <- numeric(n) # number of obs in each clusters
    c <- numeric(n) # cluster label of ech observation
    ltn <- rtruncnorm(n, a=0, b=Inf, mean=0, sd=1) # latent truncated normal
    sc <- rep(1,n)
    
    priorG1 <- prior
    nonnullpriors_ind <- which(priorG1$weights!=0)
    priorG1$weights <- priorG1$weights[nonnullpriors_ind]
    priorG1$parameters <- priorG1$parameters[nonnullpriors_ind]
    nbmix_prior <- length(priorG1[["weights"]])+1
    priorG1[["parameters"]][[nbmix_prior]] <- hyperG0
    priorG1[["parameters"]][[nbmix_prior]][["B"]] <- diag(c(priorG1[["parameters"]][[nbmix_prior]][["D_xi"]],
                                                            priorG1[["parameters"]][[nbmix_prior]][["D_psi"]])
    )
    priorG1$weights <- c(priorG1$weights, 1/length(priorG1$weights))
    priorG1$weights <- priorG1$weights/sum(priorG1$weights)
    
    a <- prior$alpha_param$shape
    b <- prior$alpha_param$rate
    
    # Initialisation----
    # each observation is assigned to a different cluster
    # or to 1 of the 50 initial clusters if there are more than
    # 50 observations
    
    i <- 1
    
    c <- sample(1:nbclust_init, size=n, replace=TRUE)
    # c <- kmeans(x=t(z), centers=t(sapply(hyperG0[["parameters"]],'[[', 'b_xi')))$cluster
    for (k in unique(c)){
        obs_k <- which(c==k)
        hyper_num <- sample(x=1:nbmix_prior, size=1)#, prob=priorG1$weights)
        priormix <- priorG1[["parameters"]][[hyper_num]]
        U_SS[[k]] <- update_SSst(z=z[, obs_k], S=priormix, ltn=ltn[obs_k], scale=sc[obs_k], df=U_df[k])
        
        NNiW <- rNNiW(U_SS[[k]], diagVar)
        U_xi[, k] <- NNiW[["xi"]]
        U_SS[[k]][["xi"]] <- NNiW[["xi"]]
        U_psi[, k] <- NNiW[["psi"]]
        U_SS[[k]][["psi"]] <- NNiW[["psi"]]
        U_Sigma[, , k] <- NNiW[["S"]]
        U_SS[[k]][["S"]] <- NNiW[["S"]]
        U_B[, ,k] <- U_SS[[k]][["B"]]
        m[k] <- length(obs_k)
        U_SS[[k]][["weight"]] <- m[k]/n
    }
    
    if(is.null(hyperG0[["alpha"]])){
        alpha <- nbmix_prior/log(n)
    }else{
        alpha <- hyperG0[["alpha"]]
    }
    
    U_SS_list[[i]] <- U_SS
    c_list[[i]] <- c
    weights_list[[1]] <- numeric(length(m))
    weights_list[[1]][unique(c)] <- table(c)/length(c)
    
    logposterior_list[[i]] <- 0#logposterior_list[[i]] <- logposterior_DPMST(z, xi=U_xi, psi=U_psi, Sigma=U_Sigma, df=U_df, B=U_B,
    #hyper=hyperG0, c=c, m=m, alpha=alpha[i], n=n, a=a, b=b, diagVar)
    
    if(doPlot){
        plot_DPMst(z=z, c=c, i=i, alpha=alpha[i], U_SS=U_SS_list[[i]], ellipses=TRUE, ...)
    }
    if(verbose){
        cat(i, "/", N, " samplings:\n", sep="",
            file=monitorfile, append = TRUE)
        cat("  logposterior = ", sum(logposterior_list[[i]]), "\n", sep="",
            file=monitorfile, append = TRUE)
        cl2print <- unique(c)
        cat(length(cl2print), "clusters:", cl2print[order(cl2print)], "\n\n",
            file=monitorfile, append = TRUE)
    }
        
    if(N>1){
        for(i in 2:N){
            nbClust <- length(unique(c))
            
            alpha <- c(alpha,
                       sample_alpha(alpha_old=alpha[i-1], n=n, 
                                    K=nbClust, a=a, b=b)
            )
            
            slice <- sliceSampler_skewT_SeqPrior_parallel(Ncpus=Ncpus,
                                                          c=c, m=m, 
                                                          alpha=alpha[i], 
                                                          z=z, priorG1=priorG1, 
                                                          U_xi=U_xi, 
                                                          U_psi=U_psi, 
                                                          U_Sigma=U_Sigma, 
                                                          U_df=U_df,
                                                          scale=sc, diagVar, 
                                                          parallel_index=par_ind)
            m <- slice[["m"]]
            c <- slice[["c"]]        
            weights_list[[i]] <- slice[["weights"]]
            ltn <- slice[["latentTrunc"]]
            U_xi <- slice[["xi"]]
            U_psi <- slice[["psi"]]        
            U_Sigma <- slice[["Sigma"]]
            U_df <- slice[["df"]]
            
            
            # Update cluster locations            
            fullCl <- which(m!=0)
            fullCl_nb <- length(fullCl)
            
            pfin <- matrix(nrow=fullCl_nb, ncol=nbmix_prior)
            U_SS_prior <- list()
            p <- matrix(nrow=nbmix_prior, ncol=fullCl_nb)
            vrais <- rep(NA,fullCl_nb)
            
            for(k in 1:fullCl_nb){
                j <- fullCl[k]
                obs_j <- which(c==j)
                U_SS_prior[[k]] <- list()
                for(l in 1:nbmix_prior){
                    U_SS_prior[[k]][[l]] <- update_SSst(z=z[, obs_j, drop=FALSE], 
                                                        S=priorG1[["parameters"]][[l]], 
                                                        ltn=ltn[obs_j], scale=sc[obs_j], 
                                                        df=U_df[j], 
                                                        hyperprior=NULL 
                    )
                }
                p[,k] <- mmsNiWpdfC(xi=U_xi[,j, drop=FALSE], psi=U_psi[,j, drop=FALSE], Sigma=list(U_Sigma[,,j]), 
                                    U_xi0=sapply(U_SS_prior[[k]], "[[", "b_xi"), 
                                    U_psi0=sapply(U_SS_prior[[k]], "[[", "b_psi"), 
                                    U_B0=lapply(U_SS_prior[[k]], "[[", "B"), 
                                    U_Sigma0=lapply(U_SS_prior[[k]], "[[", "lambda"), 
                                    U_df0=sapply(U_SS_prior[[k]], "[[", "nu"),
                                    Log=TRUE)
                vrais[k] <- sum(mmvstpdfC(x=z[,obs_j, drop=FALSE], xi=U_xi[,j, drop=FALSE], psi=U_psi[,j, drop=FALSE], 
                                          sigma=list(U_Sigma[,,j]), df=U_df[j], Log=TRUE))
            }
            p0 <- mmsNiWpdfC(xi=U_xi[, fullCl, drop=FALSE], psi=U_psi[, fullCl, drop=FALSE], 
                             Sigma=lapply(fullCl, function(m) U_Sigma[, ,m]), 
                             U_xi0=sapply(priorG1[["parameters"]], "[[", "b_xi"), 
                             U_psi0=sapply(priorG1[["parameters"]], "[[", "b_psi"), 
                             U_B0=lapply(priorG1[["parameters"]], "[[", "B"), 
                             U_Sigma0=lapply(priorG1[["parameters"]], "[[", "lambda"), 
                             U_df0=sapply(priorG1[["parameters"]], "[[", "nu"),
                             Log=TRUE)
            
            
            pfin_log <- apply(X=(p0 - p), MARGIN=1, FUN=function(r){vrais+r})
            if(is.null(dim(pfin_log))){
                logexptrick_const <- max(pfin_log)
                wfin_log_const <- pfin_log - logexptrick_const
                w2fin <- exp(wfin_log_const)*priorG1[["weights"]]
                w2fin_sums <- sum(w2fin)
                wfin <- matrix(w2fin/w2fin_sums, nrow=1)
            }else{
                logexptrick_const <- apply(X=pfin_log, MARGIN=1, FUN=max)
                wfin_log_const <- apply(X=pfin_log, MARGIN=2, FUN=function(cv){cv - logexptrick_const})
                w2fin <- apply(X=exp(wfin_log_const), MARGIN=1, FUN=function(r){r*priorG1[["weights"]]})
                w2fin_sums <- colSums(w2fin)
                #w2fin_sums0_ind <- which(w2fin_sums==0)
                #             if(length(w2fin_sums0_ind)>0){
                #                 browser()
                #                 w2fin[nbmix_prior,w2fin_sums0_ind] <- 1
                #                 w2fin_sums[w2fin_sums0_ind] <- 1
                #             }
                wfin <- apply(X=w2fin, MARGIN=1, FUN=function(r){r/w2fin_sums})
                #any(rowSums(wfin)!=1) #should all be 1
            }
            
            for(k in 1:fullCl_nb){
                j <- fullCl[k]
                obs_j <- which(c==j)
                #cat("cluster ", j, ":\n")
                
                #sample prior mixture element to update
                hyper_num <- sample(x=1:nbmix_prior, size=1, prob=wfin[k,])
                priormix <- priorG1[["parameters"]][[hyper_num]]     
                
                U_SS[[j]] <- update_SSst(z=z[, obs_j, drop=FALSE], S=priormix, 
                                         ltn=ltn[obs_j], scale=sc[obs_j], 
                                         df=U_df[j], 
                                         hyperprior = NULL 
                )
                
                U_nu[j] <- U_SS[[j]][["nu"]]
                NNiW <- rNNiW(U_SS[[j]], diagVar)
                U_xi[, j] <- NNiW[["xi"]]
                U_SS[[j]][["xi"]] <- NNiW[["xi"]]
                U_psi[, j] <- NNiW[["psi"]]
                U_SS[[j]][["psi"]] <- NNiW[["psi"]]
                U_Sigma[, , j] <- NNiW[["S"]]
                U_SS[[j]][["S"]] <- NNiW[["S"]]
                U_B[, ,j] <- U_SS[[j]][["B"]]
                U_SS[[j]][["weight"]] <- weights_list[[i]][j]
            }
            
            update_scale <- sample_scale(c=c, m=m, z=z, U_xi=U_xi, 
                                         U_psi=U_psi, U_Sigma=U_Sigma, 
                                         U_df=U_df, ltn=ltn, 
                                         weights=weights_list[[i]],
                                         scale=sc)
            U_df_list <- update_scale[["df"]]
            sc <- update_scale[["scale"]]
            
            for(k in 1:fullCl_nb){
                j <- fullCl[k]
                U_df[j] <- U_df_list[[k]]
                U_SS[[j]][["df"]] <- U_df[j]
            }
            
            U_SS_list[[i]] <- U_SS[which(m!=0)] 
            c_list[[i]] <- c
            
            logposterior_list[[i]] <- 0#logposterior_list[[i]] <- logposterior_DPMST(z, xi=U_xi, psi=U_psi, Sigma=U_Sigma, df=U_df, B=U_B,
            #hyper=hyperG0, c=c, m=m, alpha=alpha[i], n=n, a=a, b=b, diagVar)
            
            if(doPlot && i/plotevery==floor(i/plotevery)){
                plot_DPMst(z=z, c=c, i=i, alpha=alpha[i], U_SS=U_SS_list[[i]], ellipses=TRUE, ...)
            }
            if(verbose){
                cat(i, "/", N, " samplings:\n", sep="",
                    file=monitorfile, append = TRUE)
                cat("  logposterior = ", sum(logposterior_list[[i]]), "\n", sep="",
                    file=monitorfile, append = TRUE)
                cl2print <- unique(c)
                cat(length(cl2print), "clusters:", cl2print[order(cl2print)], "\n\n",
                    file=monitorfile, append = TRUE)
            }
        }
    }
    
    
    
    stopCluster(cl)
    
    dpmclus <- list("mcmc_partitions" = c_list, 
                    "alpha"=alpha, 
                    "U_SS_list"=U_SS_list,
                    "weights_list"=weights_list, 
                    "logposterior_list"=logposterior_list, 
                    "data"=z,
                    "nb_mcmcit"=N,
                    "clust_distrib"="skewT",
                    "hyperG0"=hyperG0)
    class(dpmclus) <- "DPMMclust"
    return(dpmclus)
}






