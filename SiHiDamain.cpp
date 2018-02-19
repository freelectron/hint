#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <conio.h>
#include <cstdio>
#include <cstring>
#include <string>
#include <math.h>
#include <iostream>
#include "Procedures.h"
#include "Objects.h"

using namespace std;
						      // can be accessed from many files,but should also be declared
                            //in those files;CONSTANTS should also be reinitialized probably!
int main(){
//MAIN VARIABLES AND I/O STREAM1
	ifstream infile;
    ofstream outfile;
    outfile.open("output.txt");
    const int N_const=3500;
	double g_array[N_const]; 		// GLOBAL VARIABLE
	double g_array2[N_const];
	int I=1; 	       // 1 in this case equals 1 ticker; but the order number of this ticker will be 0; I = Number of input files(tickers) to use
	int Ndays;        // number of "days"; but range with values will be [0; Ndays-1]
	ticker T1[1];      // array of tickers . ticker has attributes see input
	for (int i=0;i<I;i++){
		T1[i].fillName("microsoft corp.txt");
	};

	// Candle Day[4400];  // object
//INPUT
	for (int q=0;q<I;q++){
		int i=0;
		infile.open(T1[q].name);
		do {
			getline(infile,T1[q].date[i]);
			i++;
		}
	   	while (!infile.eof()); 		// counts number of days but includes the last NULL line
		int ndays=i; i=i-1;
		infile.clear(); infile.seekg(0,ios::beg);
		while (i!=-1){
			infile>>T1[q].date[i];
			infile>>T1[q].open[i];
			infile>>T1[q].high[i];
			infile>>T1[q].low[i];
			infile>>T1[q].close[i];
			infile>>T1[q].volume[i];
			i--;

		}; infile.clear();
		outfile<<"Days analysed: "<<(ndays)<<endl;
		Ndays=ndays;
		infile.close();
	};
//PROCEDURES
	//StochFast(g_array,g_array2,T1[0].close,T1[0].high,T1[0].low,Ndays,12,2);
	SMA(g_array,T1[0].close,Ndays,12);
	//RSI(close,g_array2,14,ndays);
//OBJECTS

	//StochCtester Stestlong(0.04,0.05,1,12,Ndays);
	//Stestlong.testlong(T1[0].close,g_array,g_array2);
	SMAtester test2(0.01,0.01,3,12,Ndays);
	test2.testShort(T1[0].close,g_array,Ndays);

//OUTPUT
	//outfile<<T1[0].date[Ndays]<<endl;
	for(int i=0;i<Ndays;i++){
	    outfile<<i<<"  "<<T1[0].date[i]<<"  "<<g_array[i]<<"   "<<g_array2[i]<<endl;
	};
	cout<<test2.countS<<"   "<<test2.count<<"  "<<test2.countS/test2.count<<endl;
	//cout<<Stestlong.countS<<"   "<<Stestlong.count<<"  "<<Stestlong.countS/Stestlong.count<<endl;
//ENDING
	outfile.close();
return 0;
}


