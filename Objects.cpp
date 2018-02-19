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

ticker:: ticker(){
	//
 	};
	void ticker::fillName(string _name){
		for (int i=0;i<_name.length();i++){
			name[i]=_name[i];
		};
	};

Candle:: Candle(){
		              // constructor default
	};
    void Candle::setDate(int m, int d, int yyyy){
    	month=m;
		day=d;
		year=yyyy;
    };


SMAtester::SMAtester(double t_Dup, double t_Ddown,int t_delay, int t_SMAperiod,int t_ndays){
		Dup=t_Dup;
		Ddown=t_Ddown;
		delay=t_delay;
		SMAperiod=t_SMAperiod;
		ndays=t_ndays;
	};

	void SMAtester::testLong(double close[],double SMA[],int ndays){
		int i=SMAperiod - 1;
		int kU,kD;
		int trend=0;
		int flag=0,flag2=0;
		double Dmid=0;
		bool check=0;
		if (close[i]>SMA[i]){
			flag=1;
		};
		i++;
		while (i<ndays){
			if (close[i]>SMA[i]){
				flag2=1;
			} else flag2=0;
			if ((flag==flag2) && (trend==1)){
				if ((trend==1)){
					if (close[i]>=SMA[i]){
						kU++;
						if ((kU>=delay) && (close[i]>=(Dmid*(1+Dup)))){
							trend=0;countS++;
							if (check==0){
								count++;
								//check=1;
							}
						};
						if ((kU>=delay) && (close[i]<(Dmid*(1+Dup)))){
							if (check==0){
								check=1;
								count++;
							};
						};
					};
				};
			};
			if (flag-flag2<0){
					kU=1;
					kD=0;
					trend=1;
					flag=flag2;
					check=0;
					Dmid=close[i+delay-1];
					} else if (flag-flag2>0) {
								kD=1;
								kU=0;
								trend=-1;
								flag=flag2;
								check=0;
								Dmid=close[i+delay-1];
						   };
			i++;
		};
	};
	void SMAtester::testShort(double close[],double SMA[], int ndays){
		int i=SMAperiod - 1;
		int j;
		int kU,kD;
		int trend=0;
		int flag=0,flag2=0;
		double Dmid=0;
		bool check;
		if (close[i]>SMA[i]){
			flag=1;
		};
		i++;
		while (i<ndays){
			if (close[i]>SMA[i]){
				flag2=1;
			} else flag2=0;
			if ((flag==flag2) && (trend==-1)){
						if ((trend==-1)){
							if (close[i]<SMA[i]){
								kD++;
								if ((kD>=delay) && (close[i]<=(Dmid*(1-Ddown)))){
									trend=0;countS++;
									if (check==0){
										count++;
										// check=1;
									};
								};
								if ((kD>=delay) && (close[i]>(Dmid*(1-Ddown)))){
									if (check==0){
										count++;
										check=1;
									};
								};
							}
						}
			}  else if (flag-flag2<0) {
							kU=1;
							kD=0;
							trend=1;
							flag=flag2;
							check=0;
							Dmid=(close[i+delay-1]);
					} else if (flag-flag2>0) {
								kD=1;
								kU=0;
								trend=-1;
								flag=flag2;
								check=0;
								Dmid=close[i+delay-1];
							};
			i++;
		};
	};
StochCtester::StochCtester(double t_Dup, double t_Ddown,int t_delay,int t_period,int t_ndays){
		Dup=t_Dup;
		Ddown=t_Ddown;
		delay=t_delay;
		ndays=t_ndays;
		period=t_period;
	};
	void StochCtester::testlong(double close[], double K[], double D[]){
		int i=1;
		int flag=0,flag2=0; //
		int trend=0,check=0, check2=0;
		double Dmid=0;
		int kf=0;           // kf= count fast = upward trend
		while (flag!=1){
				if (K[i]>D[i]){
					flag=1;
				};
				i++;
		};
		i=i-1;
		while (i<ndays){
			if (K[i]>D[i]){
					flag=1;
				} else flag=0;
			// cout<<flag<<"  ";   //
			if ((trend==1) && (flag==1)){
					if (K[i]>D[i]){
						kf++;
						if ((kf>=delay) && (close[i]>=(Dmid*(1+Dup)))){
							if (check2==0){
								countS++;
								check2=1;
							};
							if (check==0){
								count++;
								check=1;
							}
						};
						if ((kf>=delay) && (close[i]<(Dmid*(1+Dup)))){
							if (check==0){
								check=1;
								count++;
							};
						};
					};
			} else {
				if ((flag==1)){
					kf=1;
					trend=1;
					//flag=flag2;
					check=0;
					check2=0;
					Dmid=close[i+delay-1];

				};
				if ((flag==0)){
					//flag=0;
					trend=-1;
				};
				//cout<<trend<<endl;
			};
			// cout<<i<<"  "<<flag2<<"   "<<trend<<endl;
			i++;
		};
	};

