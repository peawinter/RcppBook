#include <Rcpp.h>

// [[Rcpp::export]]

extern "C" SEXP mypnorm(SEXP xx) {
  Rcpp::NumericVector x(xx);
  int n = x.size();
  Rcpp::NumericVector y1(n), y2(n), y3(n);
  
  for (int i=0; i<n; i++) {
    y1[i] = ::Rf_pnorm5(x[i], 0.0, 1.0, 1, 0);
    y2[i] = R::pnorm(x[i], 0.0, 1.0, 1, 0);
  }
  y3 = Rcpp::pnorm(x);
  
  return Rcpp::DataFrame::create(Rcpp::Named("Rf_") = y1,
                                 Rcpp::Named("R") = y2,
                                 Rcpp::Named("sugar") = y3);
}