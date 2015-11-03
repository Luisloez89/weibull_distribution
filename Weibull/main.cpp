//
//  main.cpp
//  Weibull
//


#include <iostream>
#include "weibull_estimator.h"
#include "weibull.h"
#include "integration.h"

int main(int argc, const char * argv[])
{
    float *data, *y;
    
    data = new(float[6]);
    y = new(float[6]);
    
    data[0] = 16;
    data[1] = 34;
    data[2] = 53;
    data[3] = 75;
    data[4] = 93;
    data[5] = 120;
    
    Estimator estimator(data, 6);
    estimator.rankRegressionY();
    
    Weibull weibull(data,6,estimator.getBeta(),estimator.getEta());
    y = weibull.getDistribution();
    
    std::cout<<weibull.getEta()<<"\t"<<weibull.getBeta()<<"\n";
    
    for (int i = 0; i<6; i++) {
        std::cout<<y[i]<<"\t";
    }
}
