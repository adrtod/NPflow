// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// FmeasureC
double FmeasureC(NumericVector pred, NumericVector ref);
RcppExport SEXP NPflow_FmeasureC(SEXP predSEXP, SEXP refSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericVector >::type pred(predSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type ref(refSEXP);
    __result = Rcpp::wrap(FmeasureC(pred, ref));
    return __result;
END_RCPP
}
// Fmeasure_costC
List Fmeasure_costC(NumericMatrix c);
RcppExport SEXP NPflow_Fmeasure_costC(SEXP cSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type c(cSEXP);
    __result = Rcpp::wrap(Fmeasure_costC(c));
    return __result;
END_RCPP
}
// Fmeasure_costC_arma
List Fmeasure_costC_arma(NumericMatrix c);
RcppExport SEXP NPflow_Fmeasure_costC_arma(SEXP cSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type c(cSEXP);
    __result = Rcpp::wrap(Fmeasure_costC_arma(c));
    return __result;
END_RCPP
}
// FmeasureC_par
double FmeasureC_par(NumericVector pred, NumericVector ref, int ncores);
RcppExport SEXP NPflow_FmeasureC_par(SEXP predSEXP, SEXP refSEXP, SEXP ncoresSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericVector >::type pred(predSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type ref(refSEXP);
    Rcpp::traits::input_parameter< int >::type ncores(ncoresSEXP);
    __result = Rcpp::wrap(FmeasureC_par(pred, ref, ncores));
    return __result;
END_RCPP
}
// Fmeasure_costC_par
List Fmeasure_costC_par(NumericMatrix c, int ncores);
RcppExport SEXP NPflow_Fmeasure_costC_par(SEXP cSEXP, SEXP ncoresSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type c(cSEXP);
    Rcpp::traits::input_parameter< int >::type ncores(ncoresSEXP);
    __result = Rcpp::wrap(Fmeasure_costC_par(c, ncores));
    return __result;
END_RCPP
}
// Fmeasure_costC_arma_par
List Fmeasure_costC_arma_par(NumericMatrix c, int ncores);
RcppExport SEXP NPflow_Fmeasure_costC_arma_par(SEXP cSEXP, SEXP ncoresSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type c(cSEXP);
    Rcpp::traits::input_parameter< int >::type ncores(ncoresSEXP);
    __result = Rcpp::wrap(Fmeasure_costC_arma_par(c, ncores));
    return __result;
END_RCPP
}
// lgamma_mvC
double lgamma_mvC(double x, double p);
RcppExport SEXP NPflow_lgamma_mvC(SEXP xSEXP, SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< double >::type x(xSEXP);
    Rcpp::traits::input_parameter< double >::type p(pSEXP);
    __result = Rcpp::wrap(lgamma_mvC(x, p));
    return __result;
END_RCPP
}
// mmsNiWpdfC
NumericMatrix mmsNiWpdfC(NumericMatrix xi, NumericMatrix psi, List Sigma, NumericMatrix U_xi0, NumericMatrix U_psi0, List U_B0, List U_Sigma0, NumericVector U_df0, bool Log);
RcppExport SEXP NPflow_mmsNiWpdfC(SEXP xiSEXP, SEXP psiSEXP, SEXP SigmaSEXP, SEXP U_xi0SEXP, SEXP U_psi0SEXP, SEXP U_B0SEXP, SEXP U_Sigma0SEXP, SEXP U_df0SEXP, SEXP LogSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type xi(xiSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type psi(psiSEXP);
    Rcpp::traits::input_parameter< List >::type Sigma(SigmaSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type U_xi0(U_xi0SEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type U_psi0(U_psi0SEXP);
    Rcpp::traits::input_parameter< List >::type U_B0(U_B0SEXP);
    Rcpp::traits::input_parameter< List >::type U_Sigma0(U_Sigma0SEXP);
    Rcpp::traits::input_parameter< NumericVector >::type U_df0(U_df0SEXP);
    Rcpp::traits::input_parameter< bool >::type Log(LogSEXP);
    __result = Rcpp::wrap(mmsNiWpdfC(xi, psi, Sigma, U_xi0, U_psi0, U_B0, U_Sigma0, U_df0, Log));
    return __result;
END_RCPP
}
// mmvnpdfC
NumericMatrix mmvnpdfC(NumericMatrix x, NumericMatrix mean, List varcovM, bool Log);
RcppExport SEXP NPflow_mmvnpdfC(SEXP xSEXP, SEXP meanSEXP, SEXP varcovMSEXP, SEXP LogSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type mean(meanSEXP);
    Rcpp::traits::input_parameter< List >::type varcovM(varcovMSEXP);
    Rcpp::traits::input_parameter< bool >::type Log(LogSEXP);
    __result = Rcpp::wrap(mmvnpdfC(x, mean, varcovM, Log));
    return __result;
END_RCPP
}
// mmvnpdfC_par
NumericMatrix mmvnpdfC_par(NumericMatrix x, NumericMatrix mean, List varcovM, bool Log, int ncores);
RcppExport SEXP NPflow_mmvnpdfC_par(SEXP xSEXP, SEXP meanSEXP, SEXP varcovMSEXP, SEXP LogSEXP, SEXP ncoresSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type mean(meanSEXP);
    Rcpp::traits::input_parameter< List >::type varcovM(varcovMSEXP);
    Rcpp::traits::input_parameter< bool >::type Log(LogSEXP);
    Rcpp::traits::input_parameter< int >::type ncores(ncoresSEXP);
    __result = Rcpp::wrap(mmvnpdfC_par(x, mean, varcovM, Log, ncores));
    return __result;
END_RCPP
}
// mmvsnpdfC
NumericMatrix mmvsnpdfC(NumericMatrix x, NumericMatrix xi, NumericMatrix psi, List sigma, bool Log);
RcppExport SEXP NPflow_mmvsnpdfC(SEXP xSEXP, SEXP xiSEXP, SEXP psiSEXP, SEXP sigmaSEXP, SEXP LogSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type xi(xiSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type psi(psiSEXP);
    Rcpp::traits::input_parameter< List >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< bool >::type Log(LogSEXP);
    __result = Rcpp::wrap(mmvsnpdfC(x, xi, psi, sigma, Log));
    return __result;
END_RCPP
}
// mmvsnpdfC_par
NumericMatrix mmvsnpdfC_par(NumericMatrix x, NumericMatrix xi, NumericMatrix psi, List sigma, bool Log, int ncores);
RcppExport SEXP NPflow_mmvsnpdfC_par(SEXP xSEXP, SEXP xiSEXP, SEXP psiSEXP, SEXP sigmaSEXP, SEXP LogSEXP, SEXP ncoresSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type xi(xiSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type psi(psiSEXP);
    Rcpp::traits::input_parameter< List >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< bool >::type Log(LogSEXP);
    Rcpp::traits::input_parameter< int >::type ncores(ncoresSEXP);
    __result = Rcpp::wrap(mmvsnpdfC_par(x, xi, psi, sigma, Log, ncores));
    return __result;
END_RCPP
}
// mmvstpdfC
NumericMatrix mmvstpdfC(NumericMatrix x, NumericMatrix xi, NumericMatrix psi, List sigma, NumericVector df, bool Log);
RcppExport SEXP NPflow_mmvstpdfC(SEXP xSEXP, SEXP xiSEXP, SEXP psiSEXP, SEXP sigmaSEXP, SEXP dfSEXP, SEXP LogSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type xi(xiSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type psi(psiSEXP);
    Rcpp::traits::input_parameter< List >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type df(dfSEXP);
    Rcpp::traits::input_parameter< bool >::type Log(LogSEXP);
    __result = Rcpp::wrap(mmvstpdfC(x, xi, psi, sigma, df, Log));
    return __result;
END_RCPP
}
// mmvstpdfC_par
NumericMatrix mmvstpdfC_par(NumericMatrix x, NumericMatrix xi, NumericMatrix psi, List sigma, NumericVector df, bool Log, int ncores);
RcppExport SEXP NPflow_mmvstpdfC_par(SEXP xSEXP, SEXP xiSEXP, SEXP psiSEXP, SEXP sigmaSEXP, SEXP dfSEXP, SEXP LogSEXP, SEXP ncoresSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type xi(xiSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type psi(psiSEXP);
    Rcpp::traits::input_parameter< List >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type df(dfSEXP);
    Rcpp::traits::input_parameter< bool >::type Log(LogSEXP);
    Rcpp::traits::input_parameter< int >::type ncores(ncoresSEXP);
    __result = Rcpp::wrap(mmvstpdfC_par(x, xi, psi, sigma, df, Log, ncores));
    return __result;
END_RCPP
}
// mmvtpdfC
NumericMatrix mmvtpdfC(NumericMatrix x, NumericMatrix mean, List varcovM, NumericVector df, bool Log);
RcppExport SEXP NPflow_mmvtpdfC(SEXP xSEXP, SEXP meanSEXP, SEXP varcovMSEXP, SEXP dfSEXP, SEXP LogSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type mean(meanSEXP);
    Rcpp::traits::input_parameter< List >::type varcovM(varcovMSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type df(dfSEXP);
    Rcpp::traits::input_parameter< bool >::type Log(LogSEXP);
    __result = Rcpp::wrap(mmvtpdfC(x, mean, varcovM, df, Log));
    return __result;
END_RCPP
}
// mmvtpdfC_par
NumericMatrix mmvtpdfC_par(NumericMatrix x, NumericMatrix mean, List varcovM, NumericVector df, bool Log, int ncores);
RcppExport SEXP NPflow_mmvtpdfC_par(SEXP xSEXP, SEXP meanSEXP, SEXP varcovMSEXP, SEXP dfSEXP, SEXP LogSEXP, SEXP ncoresSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type mean(meanSEXP);
    Rcpp::traits::input_parameter< List >::type varcovM(varcovMSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type df(dfSEXP);
    Rcpp::traits::input_parameter< bool >::type Log(LogSEXP);
    Rcpp::traits::input_parameter< int >::type ncores(ncoresSEXP);
    __result = Rcpp::wrap(mmvtpdfC_par(x, mean, varcovM, df, Log, ncores));
    return __result;
END_RCPP
}
// mvnpdfC
NumericVector mvnpdfC(NumericMatrix x, NumericVector mean, NumericMatrix varcovM, bool Log);
RcppExport SEXP NPflow_mvnpdfC(SEXP xSEXP, SEXP meanSEXP, SEXP varcovMSEXP, SEXP LogSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type mean(meanSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type varcovM(varcovMSEXP);
    Rcpp::traits::input_parameter< bool >::type Log(LogSEXP);
    __result = Rcpp::wrap(mvnpdfC(x, mean, varcovM, Log));
    return __result;
END_RCPP
}
// mvnpdfC_par
NumericVector mvnpdfC_par(NumericMatrix x, NumericVector mean, NumericMatrix varcovM, bool Log, int ncores);
RcppExport SEXP NPflow_mvnpdfC_par(SEXP xSEXP, SEXP meanSEXP, SEXP varcovMSEXP, SEXP LogSEXP, SEXP ncoresSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type mean(meanSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type varcovM(varcovMSEXP);
    Rcpp::traits::input_parameter< bool >::type Log(LogSEXP);
    Rcpp::traits::input_parameter< int >::type ncores(ncoresSEXP);
    __result = Rcpp::wrap(mvnpdfC_par(x, mean, varcovM, Log, ncores));
    return __result;
END_RCPP
}
// mvstlikC
List mvstlikC(NumericMatrix x, IntegerVector c, IntegerVector clustval, NumericMatrix xi, NumericMatrix psi, List sigma, NumericVector df, bool loglik);
RcppExport SEXP NPflow_mvstlikC(SEXP xSEXP, SEXP cSEXP, SEXP clustvalSEXP, SEXP xiSEXP, SEXP psiSEXP, SEXP sigmaSEXP, SEXP dfSEXP, SEXP loglikSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type c(cSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type clustval(clustvalSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type xi(xiSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type psi(psiSEXP);
    Rcpp::traits::input_parameter< List >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type df(dfSEXP);
    Rcpp::traits::input_parameter< bool >::type loglik(loglikSEXP);
    __result = Rcpp::wrap(mvstlikC(x, c, clustval, xi, psi, sigma, df, loglik));
    return __result;
END_RCPP
}
// mvstlikC_par
List mvstlikC_par(NumericMatrix x, IntegerVector c, IntegerVector clustval, NumericMatrix xi, NumericMatrix psi, List sigma, NumericVector df, bool loglik, int ncores);
RcppExport SEXP NPflow_mvstlikC_par(SEXP xSEXP, SEXP cSEXP, SEXP clustvalSEXP, SEXP xiSEXP, SEXP psiSEXP, SEXP sigmaSEXP, SEXP dfSEXP, SEXP loglikSEXP, SEXP ncoresSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type c(cSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type clustval(clustvalSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type xi(xiSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type psi(psiSEXP);
    Rcpp::traits::input_parameter< List >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type df(dfSEXP);
    Rcpp::traits::input_parameter< bool >::type loglik(loglikSEXP);
    Rcpp::traits::input_parameter< int >::type ncores(ncoresSEXP);
    __result = Rcpp::wrap(mvstlikC_par(x, c, clustval, xi, psi, sigma, df, loglik, ncores));
    return __result;
END_RCPP
}
// sampleClassC_bis
IntegerVector sampleClassC_bis(NumericMatrix probMat);
RcppExport SEXP NPflow_sampleClassC_bis(SEXP probMatSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type probMat(probMatSEXP);
    __result = Rcpp::wrap(sampleClassC_bis(probMat));
    return __result;
END_RCPP
}
// sampleClassC_bis_par
IntegerVector sampleClassC_bis_par(NumericMatrix probMat, int ncores);
RcppExport SEXP NPflow_sampleClassC_bis_par(SEXP probMatSEXP, SEXP ncoresSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type probMat(probMatSEXP);
    Rcpp::traits::input_parameter< int >::type ncores(ncoresSEXP);
    __result = Rcpp::wrap(sampleClassC_bis_par(probMat, ncores));
    return __result;
END_RCPP
}
// sampleClassC
IntegerVector sampleClassC(NumericMatrix probMat);
RcppExport SEXP NPflow_sampleClassC(SEXP probMatSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type probMat(probMatSEXP);
    __result = Rcpp::wrap(sampleClassC(probMat));
    return __result;
END_RCPP
}
// sampleClassC_par
IntegerVector sampleClassC_par(NumericMatrix probMat, int ncores);
RcppExport SEXP NPflow_sampleClassC_par(SEXP probMatSEXP, SEXP ncoresSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type probMat(probMatSEXP);
    Rcpp::traits::input_parameter< int >::type ncores(ncoresSEXP);
    __result = Rcpp::wrap(sampleClassC_par(probMat, ncores));
    return __result;
END_RCPP
}
// similarityMatC
List similarityMatC(NumericMatrix c);
RcppExport SEXP NPflow_similarityMatC(SEXP cSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type c(cSEXP);
    __result = Rcpp::wrap(similarityMatC(c));
    return __result;
END_RCPP
}
// similarityMatC_par
List similarityMatC_par(NumericMatrix c, int ncores);
RcppExport SEXP NPflow_similarityMatC_par(SEXP cSEXP, SEXP ncoresSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type c(cSEXP);
    Rcpp::traits::input_parameter< int >::type ncores(ncoresSEXP);
    __result = Rcpp::wrap(similarityMatC_par(c, ncores));
    return __result;
END_RCPP
}
// traceEpsC
NumericVector traceEpsC(NumericMatrix eps, NumericMatrix sigma);
RcppExport SEXP NPflow_traceEpsC(SEXP epsSEXP, SEXP sigmaSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type eps(epsSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type sigma(sigmaSEXP);
    __result = Rcpp::wrap(traceEpsC(eps, sigma));
    return __result;
END_RCPP
}
// traceEpsC_par
NumericVector traceEpsC_par(NumericMatrix eps, NumericMatrix sigma, int ncores);
RcppExport SEXP NPflow_traceEpsC_par(SEXP epsSEXP, SEXP sigmaSEXP, SEXP ncoresSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type eps(epsSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< int >::type ncores(ncoresSEXP);
    __result = Rcpp::wrap(traceEpsC_par(eps, sigma, ncores));
    return __result;
END_RCPP
}
