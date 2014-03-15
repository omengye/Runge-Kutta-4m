#include <iostream>
#include <cmath>
#include "linspace.h" 
#include "rk4_1st.h"

using std::vector;
using namespace std;

double f(double t, double x) {
    double dx = 0.62*pow(2*9.81*x,0.5)/(3.14*(pow(x,2)-2*x)*pow(10,4));
	// double dx=sin(t);
    return dx;
}

/*
ti    时间初值
step  步长
tf    时间结束
xi    初值
*/

int main() {
    double xi, ti, dt, tmax;

/* initial information */ 
    ti = 0.0;             // initial value for variable
    xi = 1.0;             // initial value for function
    dt = 0.1;             // step size for integration
    tmax = 2.0 ;          // inegrate from ti till tmax
	
	vector<double> yy=rk4_1st(f,ti,dt,tmax,xi);

	for (size_t i=0; i != yy.size(); ++i) {
		cout<<yy[i]<<endl;
	}
	return 0;
}
