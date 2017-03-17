#ifndef MYFEATURES_H
#define MYFEATURES_H
#include <stdlib.h>
#include <fftw3.h>
#include <vector>
#include <omp.h>
#include <iostream>
#define M_PI 3.141592653589793
using namespace std;

class myAudioFeatures {
private:
    double              Fs;
public:
    myAudioFeatures(double Fs);
    double getFundFreq(vector<double> signal,vector<double> b,vector<double> a);
    double hFactor(void);
};
#endif // MYFEATURES_H
