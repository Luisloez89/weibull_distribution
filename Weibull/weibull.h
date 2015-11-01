//
//  weibull.h
//  Weibull
//
//  Created by Sanjiv  Soni on 28/10/15.
//  Copyright (c) 2015 sunjiv. All rights reserved.
//

#ifndef Weibull_weibull_h
#define Weibull_weibull_h

class Weibull{
private:
    float *data;
    float beta;
    float eta;
    float gamma;
    int dataCount;
    
public:
    Weibull(float *_data, int dataCount, float _beta, float _eta);
    
    float* getDistribution();
    float weibullDistribution(float _x);
    
    float getBeta();
    float getEta();
    
    void setParams(float _beta, float _eta);
    void setData(float *data);
    
    float mean();
    float median();
    float mode();
    float standardDeviation();
    float reliabilityFn();
    
};

#endif
