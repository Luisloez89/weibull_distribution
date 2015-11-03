//
//  integration.h
//  Weibull
//


#ifndef __Weibull__integration__
#define __Weibull__integration__

#include <stdio.h>

class Integration{
private:
    int intervals;
public:
    Integration(const int &_intervals);
    double integrate(double (*pfun)(const double &x, const double y), const double &upBound, const double &lowBound, const double beta);
    
    
};

#endif /* defined(__Weibull__integration__) */
