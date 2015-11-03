//
//  integration.h
//  Weibull
//
//  Created by Sanjiv  Soni on 01/11/15.
//  Copyright (c) 2015 sunjiv. All rights reserved.
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
