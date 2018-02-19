#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <conio.h>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

#ifndef PROCEDURES_H_INCLUDED
#define PROCEDURES_H_INCLUDED
using namespace std;


void RSI(double close[],double resultarray[],int RSIperiod,int ndays);
void StochFast(double K[], double D[], double close[],double high[], double low[],int sizeC/*=ndays*/, int Kperiod, int Dperiod);
double AvgFromArray( double m[]);
void STD(double resultarray[], double m[],int sizeM, int n);
void SMA(double resultarray[], double m[],int sizeM, int n);
void swapDouble(double *x,double *y);
void reshuffle(string dates[], double open[],double high[],double low[], double close[],double volume[],int ndays);

#endif // PROCEDURES_H_INCLUDED


