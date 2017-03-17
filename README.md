# myFILTERS
Ring buffer FIR filtering and IIR filtering through DF-II Second Order Sections

C++

FLOATING POINT ARITHMETIC

# Description
This C++ class implements ring-buffer FIR filtering and IIR filtering through second order sections (direct-form II)

NOTES: This class does not design any filters, filter taps must be precomputed in floating point.

Example: how to get second order sections for a IIR filter with Matlab:
          
          [A,B,C,D] = butter(10,[300 600]/(Fs*0.5));
          sosMatrix = ss2sos(A,B,C,D);
          
Matlab documentation about SOS filtering:
https://es.mathworks.com/help/signal/ref/sosfilt.html

# USAGE

FIR:

            myFILTER filter= myFILTER();
            size_t nSignal = 1024;
            vector<double> signal(nSignal,1.0);
            vector<double> taps(10,0); //...FILL YOUR TAPS SOMEHOW
            vector<double> filtSignal = filter.ringFir(signal,taps);
            
IIR:

            myFILTER filter= myFILTER();
            size_t nSignal = 1024;
            vector<double> signal(nSignal,1.0);
            vector<vector<double>> sosMatrix(10); //...FILL YOUR MATRIX SOMEHOW
            vector<double> filtSignal = filter.sosFilt(signal,sosMatrix);
