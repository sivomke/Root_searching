#include "Secant_Method.h"
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

double f(double x) {
	return pow(x, 4.) - 2 * pow(x, 3.) + pow(x, 2.) - 2 * x + 1;
}
double secant_method() {
	double x_prev, x_cur = x0_, x_next = x1_, f_prev = f(x_cur), f_cur;
	int i = 0;
	cout << setw(40) << right << "Secant Method" << endl;
	cout << setw(15) << right << "k";
	cout << setw(15) << right << "x[k]";
	cout << setw(15) << right << "f(x[k])" << endl;
	while ((abs(x_next - x_cur) > eps_) || abs((f(x_next)) > eps_)) {
		cout << setw(15) << right << i;
		x_prev = x_cur;
		x_cur = x_next;
		cout << setw(15) << right << fixed << x_cur;
		f_cur = f(x_cur);
		cout << setw(15) << right << fixed << f_cur << endl;
		x_next = x_cur - (x_cur - x_prev) * f_cur / (f_cur - f_prev);
		f_prev = f_cur;
		i++;
	}
	cout << setw(15) << right << i;
	x_prev = x_cur;
	x_cur = x_next;
	cout << setw(15) << right << fixed << x_cur;
	f_cur = f(x_cur);
	cout << setw(15) << right << fixed << f_cur << endl;
	x_next = x_cur - (x_cur - x_prev) * f_cur / (f_cur - f_prev);
	return x_next;
}
