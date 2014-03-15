#ifndef LINSPACE_H
#define LINSPACE_H

/*----------------------------------------
 * 
 * Matlab type arrays in C++
 * 
 * http://stackoverflow.com/questions/11734322/matlab-type-arrays-in-c
 * 
 -----------------------------------------*/

#include <vector>
using std::vector;

// linspace(0,2,10)
vector<double> linspace(double a, double b, int n) {
    vector<double> array;
    double step = (b-a) / (n-1);

    while(a < b) {			 //	modify "<=" to "<" for the last value 
        array.push_back(a);
        a += step;           // could recode to better handle rounding errors
    }
	array.push_back(b); 	 // modify the last value
    return array;
}

// 0:0.3:1 same as steps(0,0.3,1)
vector<double> steps(double a, double b, double c) {
    vector<double> array;
    while(a <= c) {
        array.push_back(a);
        a += b;         // could recode to better handle rounding errors
    }
    return array;
}

#endif // LINSPACE_H
