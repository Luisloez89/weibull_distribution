//
//  main.cpp
//  Weibull
//


#include <iostream>
#include "weibull_estimator.h"
#include "weibull.h"
#include "integration.h"
#include "readData.h"
#define N 6

int main(int argc, const char * argv[])
{
    float *data, *y;
    
    data = new(float[N]);
    y = new(float[N]);
    
    
    
	readData("data_file.txt", data, N);
    
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
