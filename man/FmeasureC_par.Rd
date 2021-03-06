% Generated by roxygen2 (4.1.0): do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{FmeasureC_par}
\alias{FmeasureC_par}
\title{Parallel C++ implementation of the F-measure computation}
\usage{
FmeasureC_par(pred, ref, ncores = 1L)
}
\arguments{
\item{pred}{}

\item{ref}{}
}
\description{
Parallel C++ implementation of the F-measure computation
}
\examples{
c <- list(c(1,1,2,3,2,3), c(1,1,1,2,3,3),c(2,2,1,1,1,1))
similarityMatC(sapply(c, "["))

c2 <- list()
for(i in 1:100){
    c2 <- c(c2, list(rmultinom(n=1, size=3000, prob=rexp(n=3000))))
}
library(microbenchmark)
f <- function(){c3 <-sapply(c2, "[")
            similarityMatC(c3)}
microbenchmark(f(), time=1L)
}

