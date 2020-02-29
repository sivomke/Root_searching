#pragma once
#include <cmath>
const double  eps = 0.000001;
const double  q = 0.77;
const double  x0 = 2.25;
const double  left_endp = 1.5;
const double right_endp = 3;

int apriori_est();//estimates max num of iterations required to find fixed point of func g
double g(double x); //func g s.as f(r)=0 and r=g(r); chosen manualy based on theory
double fixed_point(); /*shows results of each iter step, mentions satisfaction of aposteriori check;
                        the last num in seq is fixed point of func g with tolerance = eps*/