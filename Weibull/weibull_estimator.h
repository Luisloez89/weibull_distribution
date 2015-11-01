//
//  weibull_estimator.h
//  Weibull
//
//  Created by Sanjiv  Soni on 28/10/15.
//  Copyright (c) 2015 sanjiv. All rights reserved.
//

#ifndef __Weibull__weibull_estimator__
#define __Weibull__weibull_estimator__

#include <stdio.h>
#include <math.h>

class Estimator{
    
private:
    float *data;
    float beta, gamma, eta;
    int dataCount;
    
public:
    Estimator();
    Estimator(float *_data, int _dataCount);

    void rankRegressionX();
    void rankRegressionY();
    
    float getBeta();
    float getGamma();
    float getEta();
    float getDataCount();
    float* getData();
    
    void setParams(float _beta, float _gamma, float _eta);
    void setDataCount(float _dataCount);
    void setData(float *_data);
   
};

#endif /* defined(__Weibull__weibull_estimator__) */
