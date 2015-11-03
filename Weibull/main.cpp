//
//  main.cpp
//  Weibull
//


#include <iostream>
#include "weibull_estimator.h"
#include "weibull.h"
#include "integration.h"
#define N 6

int main(int argc, const char * argv[])
{
    float *data, *y;
    
    data = new(float[N]);
    y = new(float[N]);
    
    
    
    data[0] = 16;
    data[1] = 34;
    data[2] = 53;
    data[3] = 75;
    data[4] = 93;
    data[5] = 120;
    
    Estimator estimator(data, N);
    estimator.rankRegressionY();
    
    Weibull weibull(data,N,estimator.getBeta(),estimator.getEta());
    y = weibull.getDistribution();
    
    std::cout<<"Eta "<<weibull.getEta()<<" Beta  "<<weibull.getBeta()<<"\n";
    
    for (int i = 0; i<N; i++) {
        std::cout<<y[i]<<"\t";
    }
    
    std::cout<<"\nMean"<<weibull.mean()<<"\n";

	//system("pause"); //Not needed on Mac :p
}
