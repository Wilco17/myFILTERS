#ifndef MYFILTER_H
#define MYFILTER_H
#include <iostream>
#include <vector>
class myFILTER
{
public:
    myFILTER();
    std::vector <double> ringFir(std::vector<double>& signal, std::vector<double> taps);
    std::vector<double> sosFilt(std::vector<double>& signal, std::vector<std::vector<double>> sosMatrix);
    ~myFILTER();
};

#endif // MYFILTER_H
