//
//  main.cpp
//  Weibull
//
//  Created by Sanjiv  Soni on 28/10/15.
//  Copyright (c) 2015 sunjiv. All rights reserved.
//

#include <iostream>
#include "weibull_estimator.h"

int main(int argc, const char * argv[]) {
    float *data;
    data = new(float[6]);
    
    data[0] = 16;
    data[1] = 34;
    data[2] = 53;
    data[3] = 75;
    data[4] = 93;
    data[5] = 120;
    
    Estimator estimator(data, 6);
    estimator.rankRegressionY();
    
}
