#include "myfilter.h"

myFILTER::myFILTER()
{
    std::cout <<"Filter-object created"<<std::endl;
};

myFILTER::~myFILTER(){};
//FIR filtering through RING BUFFER implementation
std::vector <double> myFILTER::ringFir(std::vector<double>& signal, std::vector<double> taps)
{
    size_t ntaps = taps.size();
    std::vector<double> buffer(ntaps,0.0);
    std::vector<double> filtSignal(signal.size(),0.0);
    int p=0;
    for (size_t kk=0;kk<signal.size();kk++)
    {
        //RING BUFFER FIR
        if(p==ntaps)
            p=0;
        buffer[p]=signal[kk];
        int m=p;
        double acc1=0.0;
        for (size_t nn=0;nn<ntaps;nn++)
        {
            if(m<0)
                acc1 += 0.0;
            else
                acc1 += taps[nn]*buffer[m];
            m--;
        }
        filtSignal[kk]=acc1;
        p++;
    }
    return filtSignal;
};

//IIR Filtering in Second Order Direct Form II Sections
std::vector<double> myFILTER::sosFilt(std::vector<double>& signal, std::vector<std::vector<double>> sosMatrix)
{
std::vector<double> filtSignal(signal.size(),0.0);
if(sosMatrix[0].size()!=6)
{
    std::cout <<"Filt Error: SOS Matrix must be a M-by-6 matrix. \n Help: https://es.mathworks.com/help/signal/ref/sosfilt.html"<<std::endl<<std::endl;
}
 else
{
    size_t numSections = sosMatrix.size();
    //Iterate over each DF-II Section
    for (size_t s=0;s<numSections;s++)
    {
        double input_ac=0.0;
        double delay1=0.0;
        double delay2=0.0;
        double auxs;
        std::vector<double> section = sosMatrix[s];
        for (size_t kk=0;kk<signal.size();kk++)
        {
            s == 0 ? auxs = signal[kk] : auxs = filtSignal[kk];
            input_ac= auxs*section[3] - section[4]*delay1 - section[5]*delay2;
            filtSignal[kk] =section[0]*input_ac + section[1]*delay1+ section[2]*delay2;
            delay2=delay1;
            delay1=input_ac;
        }
    }
}
return filtSignal;
};
