// Tell Rcpp to rely on the RcppGSL package to find GSL library and headers
// [[Rcpp::depends(RcppGSL)]]

#include <RcppGSL.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_eigen.h>

// [[Rcpp::export]]
RcppGSL::Vector getEigenValues(RcppGSL::Matrix & M) {
  int k = M.ncol();
  
  RcppGSL::Vector ev(k);  	// instead of gsl_vector_alloc(k);
  gsl_eigen_symm_workspace *w = gsl_eigen_symm_alloc(k);
  gsl_eigen_symm(M, ev, w);
  gsl_eigen_symm_free (w);
  
  return ev;				// return results vector  
}