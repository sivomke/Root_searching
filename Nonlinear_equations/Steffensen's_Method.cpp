#include "Steffensen's_Method.h"
#include "Fixed_Point_Iterator.h"
#include "Secant_Method.h"
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;



double steffensen_method() {
	double x_prev = x0_, x_next = x1_, x_aux, y_aux, f_cur; int i = 0;
	cout << setw(40) << right << "Steffensen's Method" << endl;
	cout << setw(15) << right << "k";
	cout << setw(15) << right << "x[k]";
	cout << setw(15) << right << "f(x[k])" << endl;
	while ((abs(x_next - x_prev) > eps) || ((abs(f(x_next)) > eps))) {
		cout << setw(15) << right << i;
		x_prev = x_next;
		x_aux = g(x_prev);
		y_aux = g(x_aux);
		x_next = (x_prev * y_aux - pow(x_aux, 2.)) / (y_aux - 2. * x_aux + x_prev);
		cout << setw(15) << right << fixed << x_next;
		cout << setw(15) << right << fixed << f(x_next) << endl;
		i++;
	}


	return x_next;
}