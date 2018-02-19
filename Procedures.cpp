#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <conio.h>
#include <cstdio>
#include <cstring>
#include <string>
#include <math.h>
#include <iostream>
// #include "Objects.h"
using namespace std;
    
void RSI(double close[],double RSIm[],int RSIperiod,int ndays){
	int i=1;
	double RS=0;
	double sumUP=0,sumDOWN=0;
	double avgUPi=0,avgDOWNi=0;
	for (i;i<=RSIperiod-1;i++){
		if (close[i]>close[i-1]){
			sumUP+=(close[i]-close[i-1]);
		};
		if (close[i]<close[i-1]){
			sumDOWN+=(close[i-1]-close[i]);	
		};
	};
	avgUPi=sumUP/RSIperiod;             	  		
	avgDOWNi=sumDOWN/RSIperiod;         			
	RSIm[i]=100-(100/(1+(avgUPi/avgDOWNi)));		
	i++;
	for (i;i<ndays;i++){
		if (close[i]>close[i-1]){
			sumUP=(close[i]-close[i-1]);
		} else sumUP=0;
		if (close[i]<close[i-1]){
			sumDOWN=(close[i-1]-close[i]);	
		} else sumDOWN=0;
		avgUPi=((avgUPi*(RSIperiod-1))+sumUP)/RSIperiod;     
		avgDOWNi=((avgDOWNi*(RSIperiod-1))+sumDOWN)/RSIperiod;	
		RSIm[i]=100-(100/(1+(avgUPi/avgDOWNi))); 
					        
	};
	
};
void StochFast(double K[], double D[], double close[],double high[], double low[],int sizeC, int Kperiod, int Dperiod){
	for (int i=(sizeC-1);i>Kperiod-2;i--){
		double max=0;
		double min=9999999;   // <---- sloppy, maaaaan
		for (int j=i;j>i-Kperiod;j--){
			if (max<high[j])
  			max=high[j]; 
			if (min>low[j])			
			min=low[j];
		}; 
		K[i]=((close[i]-min)/(max-min));
	};int k,t;
	for (k=sizeC-1;k>Kperiod-2+Dperiod-1;k--){
		double summ=0;
  		for (t=k;t>k-Dperiod;t--){
  			summ=summ+K[t]; // cout<<K[t]<<"   ";
		  };
	D[k]=summ/Dperiod; 
 	};
	
};
double AvgFromArray( double m[]){   // gives average just by passing an array of numbers
    int i=0;                                    
  	double sum=0;
  	for (int i=0;i<sizeof(m);i++){
  		sum=sum+m[i];
	  };
	return (sum/sizeof(m));
} 
void STD(double resultarray[], double m[],int sizeM, int n){  // res.arr= array which is being filled with std's ; m =array with number which std is calculated ; n=period
	int i=0;           // n==STDperiod
	for (i=sizeM-1;i>n-2;i--){      // func to fill resultarray with sma's from m[] which is sizM
  		double sum=0; 				// sma's with period n
  		for (int j=i;j>i-n;j--){
  			sum=sum+m[j];
	     };
	     double avg=(sum/n);
	     sum=0;
	     for(int k=i;k>i-n;k--){
	    	double sqdeviation = pow((m[k]-avg),2);
	    	sum=sum + sqdeviation;
		 };
		 resultarray[i]=sqrt((sum/n)); 
	};	
};
void SMA(double resultarray[],double m[],int sizeM, int n){    // SMAperiod == n
	int i=0;
	for (i=(sizeM-1);i>n-2;i--){      // func to fill resultarray with sma's from m[] which is sizM
  		double sum=0; 				// sma's with period n
  		for (int j=i;j>i-n;j--){
  			sum=sum+m[j];
	     };
	     resultarray[i]=(sum/n);
	}
};


void swapDouble(double *x,double *y){
	double *z;
	*z=*x;
	*x=*y;	
	*y=*z;
};

void reshuffle(string dates[], double open[],double high[],double low[], double close[],double volume[],int ndays){
	int i=0;
	if ((ndays%2)==0){
		for (i;i<((ndays)/2);i++){
			swap(dates[i],dates[ndays-i-1]);
			swap(open[i],open[ndays-i-1]);
			swap(high[i],high[ndays-i-1]);
			swap(low[i],low[ndays-i-1]);
			swap(close[i],close[ndays-i-1]);
			swap(volume[i],volume[ndays-i-1]);
			
		};
	  }  else {
		for (i;i<((ndays+1)/2);i++){
			swap(dates[i],dates[ndays-i-1]);
			swap(open[i],open[ndays-i-1]);
			swap(high[i],high[ndays-i-1]);
			swap(low[i],low[ndays-i-1]);
			swap(close[i],close[ndays-i-1]);
			swap(volume[i],volume[ndays-i-1]);
		};
	};
};

