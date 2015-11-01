//
//  weibull_estimator.cpp
//  Weibull
//
//  Created by Sanjiv  Soni on 29/10/15.
//  Copyright (c) 2015 sunjiv. All rights reserved.
//

#include "weibull_estimator.h"
#include <iostream>

Estimator::Estimator(float *_data, int _dataCount){
    this->data = _data;
    this->dataCount = _dataCount;
}

Estimator::Estimator(){
    data = nullptr;
    alpha = -1;
    beta = -1;
    gamma = -1;
    dataCount = -1;
}

void Estimator::rankRegressionY(){
    
    float a = 0, b = 0, c = 0;
    float *medianRank = new float[dataCount];
    float *y= new float[dataCount];
    
    float t1 = 0,t2 = 0,t3 = 0,t4 = 0;
    
    
    for(int i = 0; i < dataCount ;i++){
        
        medianRank[i] = (i+1-0.3)/(dataCount + 0.4)*100;
        y[i] = log(-log(1-medianRank[i]/100));
        
        t1 += y[i]*log(data[i]);
        t2 += log(data[i]);
        t3 += y[i];
        t4 += (log(data[i])*log(data[i]));
        
        //std::cout<<medianRank[i]<<"\t";
    }
    
    b = (t1 - t2*t3/dataCount)/(t4 - t2*t2/dataCount);
    
    a = t3/dataCount-b*t2/dataCount;
    
    c = exp(-a/b);
    
    std::cout<<b<<"\t"<<a<<"\t"<<c;
    
    
}
