#ifndef RK4_1ST_H
#define RK4_1ST_H

#include "linspace.h" 
#include <vector>

using std::vector;
using namespace std;

vector<double> rk4_1st(double(*f)(double, double), const double ti, const double step, const double tf, const double xi) {
	vector<double> xf;
	xf.push_back(xi);
	double k1, k2, k3, k4;
	
	vector<double> step_t = steps(ti, step, tf); // 将时间t用linspace.h中step函数等分
	
	for (size_t i=0; i != step_t.size(); ++i) {
		k1 = step*f(step_t[i], xf[i]);
		k2 = step*f(step_t[i]+step/2.0,xf[i]+k1/2.0);
		k3 = step*f(step_t[i]+step/2.0,xf[i]+k2/2.0);
		k4 = step*f(step_t[i]+step,xf[i]+k3);
		xf.push_back( xf[i]+(k1+2.0*(k2+k3)+k4)/6.0 );
	}
	return xf;
}

#endif
