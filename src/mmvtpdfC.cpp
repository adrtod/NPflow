#include <RcppArmadillo.h>
using namespace Rcpp;
using namespace arma;

// [[Rcpp::depends(RcppArmadillo)]]

//' C++ implementation of multivariate Normal probability density function for multiple inputs
//'
//'@param x data matrix of dimension p x n, p being the dimension of the 
//'data and n the number of data points 
//'@param mean mean vectors matrix of dimension p x K, K being the number of 
//'distributions for which the density probability has to be ealuated
//'@param varcovM list of length K of variance-covariance matrices, 
//'each of dimensions p x p
//'@param df vector of length K of degree of freedom parameters
//'@param logical flag for returning the log of the probability density 
//'function. Defaults is \code{TRUE}.
//'@return matrix of densities of dimension K x n
//'@export
//'@examples
//'mvnpdf(x=matrix(1.96), mean=0, varcovM=diag(1), Log=FALSE)
//'mvtpdf(x=matrix(1.96), mean=0, varcovM=diag(1), df=10000000, Log=FALSE)
//'mmvtpdfC(x=matrix(1.96), mean=matrix(0), varcovM=list(diag(1)), df=10000000, Log=FALSE)
//'mvnpdf(x=matrix(1.96), mean=0, varcovM=diag(1))
//'mvtpdf(x=matrix(1.96), mean=0, varcovM=diag(1), df=10000000)
//'mmvtpdfC(x=matrix(1.96), mean=matrix(0), varcovM=list(diag(1)), df=10000000)
//'
//'mvtpdf(x=matrix(1.96), mean=0, varcovM=diag(1), df=10)
//'mmvtpdfC(x=matrix(1.96), mean=matrix(0), varcovM=list(diag(1)), df=10)
//'
//'
//'library(microbenchmark)
//'microbenchmark(mvtpdf(x=matrix(1.96), mean=0, varcovM=diag(1), Log=FALSE),
//'               #mvpdfC(x=matrix(1.96), mean=0, varcovM=diag(1), Log=FALSE),
//'               mmvtpdfC(x=matrix(1.96), mean=matrix(0), varcovM=list(diag(1)), Log=FALSE),
//'               times=10000L)
//'
// [[Rcpp::export]]
NumericMatrix mmvtpdfC(NumericMatrix x, 
                       NumericMatrix mean, 
                       List varcovM, 
                       NumericVector df,
                       bool Log=true){
    
    mat xx = as<mat>(x);
    mat m = as<mat>(mean); 
    int p = xx.n_rows;
    int n = xx.n_cols;
    int K = m.n_cols;
    NumericMatrix y = NumericMatrix(K,n);
    
    for(int k=0; k < K; k++){
        mat S = varcovM[k];
        mat Rinv = inv(trimatu(chol(S)));
        double logSqrtDetvarcovM = sum(log(Rinv.diag()));
        colvec mtemp = m.col(k);
        double dftemp = df(k);
        
        for (int i=0; i < n; i++) {
            colvec x_i = xx.col(i) - mtemp;
            rowvec xRinv = trans(x_i)*Rinv;
            double quadform = sum(xRinv%xRinv);
            double a = lgamma((dftemp + p)/2) - lgamma(dftemp/2) - log(dftemp*M_PI)*p/2 ;
            if (!Log) {
                y(k,i) = pow((1 + quadform/dftemp),(-(dftemp + p)/2))*exp(a+logSqrtDetvarcovM) ;
            } else{
                y(k,i) = (-(dftemp + p)/2)*log(1 + quadform/dftemp) + a + logSqrtDetvarcovM ;
            } 
        }
        
    }
    
    return y;
    
}





