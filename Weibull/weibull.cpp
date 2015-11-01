//
//  weibull.cpp
//  Weibull
//
//  Created by Sanjiv  Soni on 29/10/15.
//  Copyright (c) 2015 sanjiv. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "weibull.h"

Weibull::Weibull(float *_data, int _dataCount, float _beta, float _eta){
    
    this->dataCount = _dataCount;
    this->data = _data;
    this->beta = _beta;
    this->eta = _eta;
}

float Weibull::weibullDistribution(float _x){
    
    return (beta/eta)*pow((_x/eta),(beta-1))*exp(-(_x/eta));
}

float* Weibull::getDistribution(){
    
    float *y;
    y = new float[dataCount];
    
    for (int i=0; i<dataCount; i++) {
        y[i] = weibullDistribution(data[i]);
    }
    return y;
}

void Weibull::setParams(float _beta, float _eta){
    this->beta = _beta;
    this->eta = _eta;
}

void Weibull::setData(float *_data){
    this->data = _data;
}

float Weibull::getBeta(){ return beta; }
float Weibull::getEta(){ return eta; }



