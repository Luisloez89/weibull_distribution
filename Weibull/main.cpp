//
//  main.cpp
//  Weibull
//


#include <iostream>
#include "weibull_estimator.h"
#include "weibull.h"
#include "integration.h"
#include "readData.h"

int main(int argc, const char * argv[])
{
    float *data, *y;
    
    data = new(float[6]);
    y = new(float[6]);
    
	readData("data_file.txt", data, 6);
    
    Estimator estimator(data, 6);
    estimator.rankRegressionY();
    
    Weibull weibull(data,6,estimator.getBeta(),estimator.getEta());
    y = weibull.getDistribution();
    
    std::cout<<weibull.getEta()<<"  "<<weibull.getBeta()<<"\n";
    
    for (int i = 0; i<6; i++) {
        std::cout<<y[i]<<"\t";
    }
    
    std::cout<<"\nMean"<<weibull.mean()<<"\n";

	system("pause");
}
