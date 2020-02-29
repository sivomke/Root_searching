#include "Fixed_Point_Iterator.h"
#include "Secant_Method.h"
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int apriori_est() {
	double frac = log((right_endp - left_endp) / (eps * (1 - q))) / log(1 / q);
	return (floor(frac) + 1);
}

double g(double x) {
	return pow((2 * pow(x, 3) - pow(x, 2) + 2 * x - 1), 1. / 4);
}


double fixed_point() {
	double x_prev, x_cur = x0, tol; int i = 1, i_max = apriori_est(); bool auxiliary = false;
	tol = (1 - q) * eps / q;
	cout.precision(8);
	cout << setw(40) << right << "Fixed Point Iterator" << endl;
	cout << setw(15) << right << "k";
	cout << setw(15) << right << "x[k]";
	cout << setw(15) << right << "f(x[k])" << endl;

	while (i <= i_max) {
		cout << setw(15) << right << i;
		x_prev = x_cur;
		cout << setw(15) << right << fixed << x_prev;
		x_cur = g(x_prev);
		cout << setw(15) << right << fixed << f(x_cur);
		if (((abs(x_cur - x_prev)) <= tol) and (auxiliary == false)) {
			cout << " a posteriori estimation is satisfied";
			auxiliary = true;
		}
		cout << endl;
		i++;
	}
	return x_cur;
}