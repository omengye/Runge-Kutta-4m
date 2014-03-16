#include <iostream>
#include <cmath>
#include "rk4_2nd.h"
#include "linspace.h"

/*
  Definition of the x'(t) = f1(t,x,x') = x' by the definition
*/

double f1(double t, double x, double v) {
	double d1x;
    d1x = v;
    return d1x;
}

/*
 *  Definition of the x"(t) = f2(t,x,x')
*/

double f2(double t, double x, double v) {
    double d2x;
	d2x = -1.0*x;  //simple harmonic oscillator
    return d2x;
}

int main()
{
    double ti, dt, tmax, xi, vi;

/* initial information */

    ti = 0.0;             // initial value for variable
    dt = 0.1;             // step size for integration
    tmax = 1.0;           // integrate from ti till tmax
	xi = 0.0;             // initial value for function x(t)
    vi = 1.0;             // initial

/* integration of ODE */
    
	vector< vector<double> > xv_f = rk4_2nd(f1,f2,ti,dt,tmax,xi,vi);

	for (size_t i=0; i != xv_f.size(); ++i) {
		for (size_t j=0; j != xv_f[i].size(); ++j)
			cout<<xv_f[i][j]<<" ";
		cout<<endl;
	}

	vector<double> step_t = steps(0, 0.1, 1);
	for (size_t it=0; it != step_t.size(); ++it) {
		cout<<step_t[it]<<" ";
	}

    return 0;
}
