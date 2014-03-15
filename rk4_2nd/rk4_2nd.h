#ifndef RK4_2ND_H
#define RK4_2ND_H

#include <vector>
#include "linspace.h"

using namespace std;
using std::vector;

vector< vector<double> > rk4_2nd(double(*d1x)(double, double, double), double(*d2x)(double, double, double),
               const double ti, const double step, const double tf, const double xi,const  double vi) {
      
/*   
	分为两行, 
	"Multi-dimensional vector", "http://stackoverflow.com/questions/823562/multi-dimensional-vector" 
    "multidimensional vector, how to", "http://www.cplusplus.com/forum/general/833/"
*/
	
	vector< vector<double> >  xv_f;            // 两行
	for (int i = 0; i < 2; i++) {
		xv_f.push_back(vector<double>());       // Add an empty row
	}
	
	vector<double> step_t = steps(ti, step, tf); // 将时间t用linspace.h中step函数等分
	double k1x,k2x,k3x,k4x,k1v,k2v,k3v,k4v;
	
	xv_f[0].push_back(xi); // 赋初值
	xv_f[1].push_back(vi);

	for (size_t i=0; i+1 != step_t.size(); ++i) {
		
		k1x = step*d1x(step_t[i], xv_f[0][i], xv_f[1][i]);
		k1v = step*d2x(step_t[i], xv_f[0][i], xv_f[1][i]);
		
		k2x = step*d1x(step_t[i]+step/2.0, xv_f[0][i]+k1x/2.0, xv_f[1][i]+k1v/2.0);
		k2v = step*d2x(step_t[i]+step/2.0, xv_f[0][i]+k1x/2.0, xv_f[1][i]+k1v/2.0);
		
		k3x = step*d1x(step_t[i]+step/2.0, xv_f[0][i]+k2x/2.0, xv_f[1][i]+k2v/2.0);
		k3v = step*d2x(step_t[i]+step/2.0, xv_f[0][i]+k2x/2.0, xv_f[1][i]+k2v/2.0);
		
		k4x = step*d1x(step_t[i]+step, xv_f[0][i]+k3x, xv_f[1][i]+k3v);
		k4v = step*d2x(step_t[i]+step, xv_f[0][i]+k3x, xv_f[1][i]+k3v);
		
		xv_f[0].push_back( xv_f[0][i]+( k1x + 2.0*(k2x+k3x) +k4x)/6.0 );
		xv_f[1].push_back( xv_f[1][i]+( k1v + 2.0*(k2v+k3v) +k4v)/6.0 );
		
	}

	return xv_f;
}
#endif
