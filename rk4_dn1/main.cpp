#include <iostream>
#include <cmath>
#include "linspace.h"
#include "rk4_dn1.h" 

using namespace std;
using std::vector;

/* global variables */
const double g = 9.81;               // free fall acceleration in m/s^2

const double rad = 3.1415926/180.0;  // radians

vector<double> dnx(double t, vector<double> x) {

	vector<double> dx(4,0.0); // 初始化
	dx[0] = x[2];
	dx[1] = x[3];
	dx[2] = 0.0;
	dx[3] = (-1.0)*g;

	return dx;
}

int main()
{

/* initial information */
    double ti = 0.0;                // initial value for variable t
    double v0 = 180.0;              // initial speed (m/s)
    double a0 =  45.0;              // initial angle (degrees)

    vector<double> xi(4,0.0);         // 初始化初值

    xi[0] = 0.0;             // initial position in x (m)
    xi[1] = 0.0;             // initial position in y (m)
    xi[2] = v0*cos(a0*rad);  // initial speed in x direction (m.s)
    xi[3] = v0*sin(a0*rad);  // initial speed in y direction (m/s)
    
    double dt = 0.1;             // step size for integration (s)
    double tmax = 1.0;          // integrate till tmax (s)

/* integration of ODE */
    
	vector< vector<double> > xf = rk4_dn1(dnx, ti, dt, tmax, xi);

	for (size_t i=0; i != xf.size(); ++i) {
		for (size_t j=0; j != xf[i].size(); ++j)
			cout<<xf[i][j]<<" ";
		cout<<endl;
	}

	vector<double> step_t = steps(0, 0.1, 1);
	for (size_t it=0; it != step_t.size(); ++it) {
		cout<<step_t[it]<<" ";
	}

    return 0;
}
