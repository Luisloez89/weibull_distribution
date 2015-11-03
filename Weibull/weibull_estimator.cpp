//
//  weibull_estimator.cpp
//  Weibull


#include "weibull_estimator.h"

Estimator::Estimator(float *_data, int _dataCount){
    this->data = _data;
    this->dataCount = _dataCount;
    beta = 0;
    gamma = 0;
    eta = 0;
}

Estimator::Estimator(){
    data = nullptr;
    beta = -1;
    gamma = -1;
    dataCount = -1;
}

void Estimator::rankRegressionY(){
    
    float a = 0;
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
        
    }
    
    this->beta = (t1 - t2*t3/dataCount)/(t4 - t2*t2/dataCount);
    a = t3/dataCount-beta*t2/dataCount;
    this->eta = exp(-a/beta);
    
}

void Estimator::setParams(float _beta, float _gamma, float _eta){
    this->beta = _beta;
    this->gamma = _gamma;
    this->eta = _eta;
}

void Estimator::setDataCount(float _dataCount){ this->dataCount = _dataCount;   }
void Estimator::setData(float *_data){  this->data = _data; }

float Estimator::getBeta(){ return this->beta; }
float Estimator::getEta(){ return this->eta; }
float Estimator::getDataCount() { return this-> dataCount; }
float* Estimator::getData() { return this->data; }

