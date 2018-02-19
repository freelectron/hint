#ifndef OBJECTS_H
#define OBJECTS_H


#include <conio.h>
#include <cstdio>
#include <cstring>
#include <string>
#include <math.h>


const int N_const=3500;

class ticker {
	public:
		ticker();
		char name[20];
		double open[N_const],high[N_const],low[N_const],close[N_const],volume[N_const]; 
		string date[N_const];
		void fillName(string _name);
	
};
class Candle{
public:
	Candle();
    int month;     
    int day;
    int year;
    double open,high,low,close,volume;
    double ibw;                // my indicator of up/down day trend 
    void setDate(int m, int d, int yyyy);                
	
};

class SMAtester{
public:
	SMAtester(double t_Dup, double t_Ddown,int t_delay, int t_SMAperiod,int t_ndays);
	double Dup,Ddown;
	int delay;
	int SMAperiod;
	int ndays;
	double count;
	double countS;
	//  void test(double close[],double open[],double SMA[], int ndays);
	void testLong(double close[],double SMA[], int ndays);     // test for buy
	void testShort(double close[],double SMA[], int ndays); 
};
class StochCtester{  // = stochastic crossing tester
public:
	StochCtester(double t_Dup, double t_Ddown, int t_delay,int t_period,int t_ndays);
	int delay;
	int ndays;
	int period; 		// period of K (fast stoch)
	double Dup, Ddown;
	double count, countS;
	void testlong (double close[], double K[], double D[]);
	
};

#endif // Objects_H
