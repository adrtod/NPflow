% Generated by roxygen2 (4.1.0): do not edit by hand
% Please edit documentation in R/postProcess.DPMMclust.R
\name{MLE_gamma}
\alias{MLE_gamma}
\title{MLE for Gamma distribution}
\usage{
MLE_gamma(g)
}
\description{
Maximum likelihood estimation of Gamma distributed observations
distribution parameters
}
\examples{
g_list <- list()
for(i in 1:1000){
 g_list <- c(g_list, rgamma(1, shape=100, rate=5))
}

mle <- MLE_gamma(g_list)
mle
}

