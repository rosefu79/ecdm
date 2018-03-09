// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// ClassbyQmat
arma::mat ClassbyQmat(unsigned int K);
RcppExport SEXP _ecdm_ClassbyQmat(SEXP KSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int >::type K(KSEXP);
    rcpp_result_gen = Rcpp::wrap(ClassbyQmat(K));
    return rcpp_result_gen;
END_RCPP
}
// sim_Y_dina
arma::mat sim_Y_dina(unsigned int N, unsigned int J, const arma::vec& CLASS, const arma::mat& ETA, const arma::vec& gs, const arma::vec& ss);
RcppExport SEXP _ecdm_sim_Y_dina(SEXP NSEXP, SEXP JSEXP, SEXP CLASSSEXP, SEXP ETASEXP, SEXP gsSEXP, SEXP ssSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int >::type N(NSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type J(JSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type CLASS(CLASSSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type ETA(ETASEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type gs(gsSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type ss(ssSEXP);
    rcpp_result_gen = Rcpp::wrap(sim_Y_dina(N, J, CLASS, ETA, gs, ss));
    return rcpp_result_gen;
END_RCPP
}
// edina_Gibbs_Q
Rcpp::List edina_Gibbs_Q(const arma::mat& Y, unsigned int K, unsigned int burnin, unsigned int chain_length);
RcppExport SEXP _ecdm_edina_Gibbs_Q(SEXP YSEXP, SEXP KSEXP, SEXP burninSEXP, SEXP chain_lengthSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type K(KSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type burnin(burninSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type chain_length(chain_lengthSEXP);
    rcpp_result_gen = Rcpp::wrap(edina_Gibbs_Q(Y, K, burnin, chain_length));
    return rcpp_result_gen;
END_RCPP
}
// errum_Gibbs_Q
Rcpp::List errum_Gibbs_Q(const arma::mat& Y, unsigned int K, unsigned int burnin, unsigned int chain_length);
RcppExport SEXP _ecdm_errum_Gibbs_Q(SEXP YSEXP, SEXP KSEXP, SEXP burninSEXP, SEXP chain_lengthSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type K(KSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type burnin(burninSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type chain_length(chain_lengthSEXP);
    rcpp_result_gen = Rcpp::wrap(errum_Gibbs_Q(Y, K, burnin, chain_length));
    return rcpp_result_gen;
END_RCPP
}
// simrRUM
arma::mat simrRUM(unsigned int N, unsigned int J, unsigned int K, const arma::mat& Q, const arma::mat& rstar, const arma::vec& pistar, const arma::mat& alpha);
RcppExport SEXP _ecdm_simrRUM(SEXP NSEXP, SEXP JSEXP, SEXP KSEXP, SEXP QSEXP, SEXP rstarSEXP, SEXP pistarSEXP, SEXP alphaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int >::type N(NSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type J(JSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type K(KSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type Q(QSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type rstar(rstarSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type pistar(pistarSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type alpha(alphaSEXP);
    rcpp_result_gen = Rcpp::wrap(simrRUM(N, J, K, Q, rstar, pistar, alpha));
    return rcpp_result_gen;
END_RCPP
}
// parm_update
Rcpp::List parm_update(unsigned int N, unsigned int J, unsigned int K, unsigned int C, const arma::mat Y, const arma::mat& Q, arma::mat& alpha, arma::cube& X, arma::mat& Smat, arma::mat& Gmat, arma::vec& pi, const arma::vec vv, const arma::vec& delta0);
RcppExport SEXP _ecdm_parm_update(SEXP NSEXP, SEXP JSEXP, SEXP KSEXP, SEXP CSEXP, SEXP YSEXP, SEXP QSEXP, SEXP alphaSEXP, SEXP XSEXP, SEXP SmatSEXP, SEXP GmatSEXP, SEXP piSEXP, SEXP vvSEXP, SEXP delta0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int >::type N(NSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type J(JSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type K(KSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type C(CSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type Q(QSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< arma::cube& >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Smat(SmatSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Gmat(GmatSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type pi(piSEXP);
    Rcpp::traits::input_parameter< const arma::vec >::type vv(vvSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type delta0(delta0SEXP);
    rcpp_result_gen = Rcpp::wrap(parm_update(N, J, K, C, Y, Q, alpha, X, Smat, Gmat, pi, vv, delta0));
    return rcpp_result_gen;
END_RCPP
}
// rRUM_Gibbs
Rcpp::List rRUM_Gibbs(const arma::mat& Y, const arma::mat& Q, unsigned int chain_length);
RcppExport SEXP _ecdm_rRUM_Gibbs(SEXP YSEXP, SEXP QSEXP, SEXP chain_lengthSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type Q(QSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type chain_length(chain_lengthSEXP);
    rcpp_result_gen = Rcpp::wrap(rRUM_Gibbs(Y, Q, chain_length));
    return rcpp_result_gen;
END_RCPP
}
// parm_update_MH
Rcpp::List parm_update_MH(unsigned int N, unsigned int J, unsigned int K, unsigned int C, const arma::mat Y, const arma::mat& Q, arma::mat& alpha, arma::vec& pistar, arma::mat& rstar, arma::vec& pi, const arma::vec vv, const arma::vec& delta0, double delta, const arma::mat& Amat);
RcppExport SEXP _ecdm_parm_update_MH(SEXP NSEXP, SEXP JSEXP, SEXP KSEXP, SEXP CSEXP, SEXP YSEXP, SEXP QSEXP, SEXP alphaSEXP, SEXP pistarSEXP, SEXP rstarSEXP, SEXP piSEXP, SEXP vvSEXP, SEXP delta0SEXP, SEXP deltaSEXP, SEXP AmatSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int >::type N(NSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type J(JSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type K(KSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type C(CSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type Q(QSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type pistar(pistarSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type rstar(rstarSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type pi(piSEXP);
    Rcpp::traits::input_parameter< const arma::vec >::type vv(vvSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type delta0(delta0SEXP);
    Rcpp::traits::input_parameter< double >::type delta(deltaSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type Amat(AmatSEXP);
    rcpp_result_gen = Rcpp::wrap(parm_update_MH(N, J, K, C, Y, Q, alpha, pistar, rstar, pi, vv, delta0, delta, Amat));
    return rcpp_result_gen;
END_RCPP
}
// rRUM_MH
Rcpp::List rRUM_MH(const arma::mat& Y, const arma::mat& Q, arma::mat& Amat, double delta, unsigned int chain_length);
RcppExport SEXP _ecdm_rRUM_MH(SEXP YSEXP, SEXP QSEXP, SEXP AmatSEXP, SEXP deltaSEXP, SEXP chain_lengthSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type Q(QSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Amat(AmatSEXP);
    Rcpp::traits::input_parameter< double >::type delta(deltaSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type chain_length(chain_lengthSEXP);
    rcpp_result_gen = Rcpp::wrap(rRUM_MH(Y, Q, Amat, delta, chain_length));
    return rcpp_result_gen;
END_RCPP
}
// OddsRatio
arma::mat OddsRatio(unsigned int N, unsigned int J, const arma::mat& Yt);
RcppExport SEXP _ecdm_OddsRatio(SEXP NSEXP, SEXP JSEXP, SEXP YtSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int >::type N(NSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type J(JSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type Yt(YtSEXP);
    rcpp_result_gen = Rcpp::wrap(OddsRatio(N, J, Yt));
    return rcpp_result_gen;
END_RCPP
}
// bijectionvector
arma::vec bijectionvector(unsigned int K);
RcppExport SEXP _ecdm_bijectionvector(SEXP KSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int >::type K(KSEXP);
    rcpp_result_gen = Rcpp::wrap(bijectionvector(K));
    return rcpp_result_gen;
END_RCPP
}
// inv_bijectionvector
arma::vec inv_bijectionvector(unsigned int K, double CL);
RcppExport SEXP _ecdm_inv_bijectionvector(SEXP KSEXP, SEXP CLSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int >::type K(KSEXP);
    Rcpp::traits::input_parameter< double >::type CL(CLSEXP);
    rcpp_result_gen = Rcpp::wrap(inv_bijectionvector(K, CL));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_ecdm_ClassbyQmat", (DL_FUNC) &_ecdm_ClassbyQmat, 1},
    {"_ecdm_sim_Y_dina", (DL_FUNC) &_ecdm_sim_Y_dina, 6},
    {"_ecdm_edina_Gibbs_Q", (DL_FUNC) &_ecdm_edina_Gibbs_Q, 4},
    {"_ecdm_errum_Gibbs_Q", (DL_FUNC) &_ecdm_errum_Gibbs_Q, 4},
    {"_ecdm_simrRUM", (DL_FUNC) &_ecdm_simrRUM, 7},
    {"_ecdm_parm_update", (DL_FUNC) &_ecdm_parm_update, 13},
    {"_ecdm_rRUM_Gibbs", (DL_FUNC) &_ecdm_rRUM_Gibbs, 3},
    {"_ecdm_parm_update_MH", (DL_FUNC) &_ecdm_parm_update_MH, 14},
    {"_ecdm_rRUM_MH", (DL_FUNC) &_ecdm_rRUM_MH, 5},
    {"_ecdm_OddsRatio", (DL_FUNC) &_ecdm_OddsRatio, 3},
    {"_ecdm_bijectionvector", (DL_FUNC) &_ecdm_bijectionvector, 1},
    {"_ecdm_inv_bijectionvector", (DL_FUNC) &_ecdm_inv_bijectionvector, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_ecdm(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
