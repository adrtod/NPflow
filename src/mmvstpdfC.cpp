#include <RcppArmadillo.h>
using namespace Rcpp;
using namespace arma;

// [[Rcpp::depends(RcppArmadillo)]]

//' C++ implementation of multivariate Normal probability density function for multiple inputs
//'
//'@param x data matrix of dimension p x n, p being the dimension of the 
//'data and n the number of data points 
//'@param xi mean vectors matrix of dimension p x K, K being the number of 
//'distributions for which the density probability has to be ealuated
//'@param psi skew parameter vectors matrix of dimension p x K, K being the number of 
//'distributions for which the density probability has to be ealuated
//'@param varcovM list of length K of variance-covariance matrices, 
//'each of dimensions p x p
//'@param df vector of length K of degree of freedom parameters
//'@param logical flag for returning the log of the probability density 
//'function. Defaults is \code{TRUE}.
//'@return matrix of densities of dimension K x n
//'@export
//'@examples
//'
//'mmvstpdfC(x = matrix(c(3.399890,-5.936962), ncol=1), xi=matrix(c(0.2528859,-2.4234067), ncol=1), 
//'psi=matrix(c(11.20536,-12.51052), ncol=1), 
//'sigma=list(matrix(c(0.2134011, -0.2382573, -0.2382573, 0.2660086), ncol=2)), 
//'df=c(7.784106)
//')
//'mvstpdf(x = matrix(c(3.399890,-5.936962), ncol=1), xi=matrix(c(0.2528859,-2.4234067), ncol=1), 
//'psi=matrix(c(11.20536,-12.51052), ncol=1), 
//'sigma=list(matrix(c(0.2134011, -0.2382573, -0.2382573, 0.2660086), ncol=2)), 
//'df=c(7.784106)
//')
//'
//'#skew-normal limit
//'mmvsnpdfC(x=matrix(rep(1.96,2), nrow=2, ncol=1), 
//'          xi=matrix(c(0, 0)), psi=matrix(c(1, 1),ncol=1), sigma=list(diag(2))
//'          )
//'mvstpdf(x=matrix(rep(1.96,2), nrow=2, ncol=1),
//'        xi=c(0, 0), psi=c(1, 1), sigma=diag(2),
//'        df=100000000
//'        )
//'mmvstpdfC(x=matrix(rep(1.96,2), nrow=2, ncol=1), 
//'          xi=matrix(c(0, 0)), psi=matrix(c(1, 1),ncol=1), sigma=list(diag(2)),
//'          df=100000000
//'          )
//'          
//'#non-skewed limit         
//'mmvtpdfC(x=matrix(rep(1.96,2), nrow=2, ncol=1),
//'         mean=matrix(c(0, 0)), varcovM=list(diag(2)),
//'         df=10
//'         )
//'mmvstpdfC(x=matrix(rep(1.96,2), nrow=2, ncol=1), 
//'          xi=matrix(c(0, 0)), psi=matrix(c(0, 0),ncol=1), sigma=list(diag(2)),
//'          df=10
//'          )
//'
//'library(microbenchmark)
//'microbenchmark(mvstpdf(x=matrix(rep(1.96,2), nrow=2, ncol=1), 
//'                       xi=c(0, 0), psi=c(1, 1), 
//'                       sigma=diag(2), df=10),
//'               mmvstpdfC(x=matrix(rep(1.96,2), nrow=2, ncol=1),
//'                         xi=matrix(c(0, 0)), psi=matrix(c(1, 1),ncol=1), 
//'                         sigma=list(diag(2)), df=10),
//'               times=10000L)
//'
// [[Rcpp::export]]
NumericMatrix mmvstpdfC(NumericMatrix x, 
                        NumericMatrix xi, 
                        NumericMatrix psi, 
                        List sigma, 
                        NumericVector df,
                        bool Log=true){
    
    mat xx = as<mat>(x);
    mat mxi = as<mat>(xi); 
    mat mpsi = as<mat>(psi); 
    int p = xx.n_rows;
    int n = xx.n_cols;
    int K = mxi.n_cols;
    NumericMatrix y = NumericMatrix(K,n);
    
    for(int k=0; k < K; k++){
        colvec mtemp = mxi.col(k);
        mat psitemp = mpsi.col(k);
        mat sigmatemp = sigma[k];
        double dftemp = df(k);
        
        mat omega = sigmatemp + psitemp*trans(psitemp);
        mat omegaInv = inv_sympd(omega);
        mat Rinv=inv(trimatu(chol(omega)));
        mat smallomega = diagmat(sqrt(diagvec(omega)));
        vec alphnum = smallomega*omegaInv*psitemp;
        mat alphtemp =sqrt(1-trans(psitemp)*omegaInv*psitemp);
        vec alphden = rep(alphtemp(0,0), alphnum.size());
        vec alph = alphnum/alphden;
        double logSqrtDetvarcovM = sum(log(Rinv.diag()));
        
        for (int i=0; i < n; i++) {
            colvec x_i = xx.col(i) - mtemp;
            rowvec xRinv = trans(x_i)*Rinv;
            mat Qy = x_i.t()*omegaInv*x_i;
            double quadform = sum(xRinv%xRinv);
            double a = lgamma((dftemp + p)/2) - lgamma(dftemp/2) - log(dftemp*M_PI)*p/2;
            double part1 = log(2) +(-(dftemp + p)/2)*log(1 + quadform/dftemp) + a+logSqrtDetvarcovM ;
            //double part1 = 2*pow((1 + quadform/dftemp),(-(dftemp + p)/2))*exp(a+logSqrtDetvarcovM);
            mat quant = trans(alph)*diagmat(1/sqrt(diagvec(omega)))*x_i*sqrt((dftemp + p)/(dftemp+Qy));
            double part2 = ::Rf_pt(quant(0,0), (dftemp + p) , 1, 0);
            if (!Log) {
                y(k,i) = exp(part1)*part2;
            } else{
                y(k,i) = part1 + log(part2);
            }
        }
    }
    
    return y;
    
}
