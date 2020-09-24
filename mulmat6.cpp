#include <iostream>
#include <stdio.h>      
#include <stdlib.h>    
#include <time.h> 
#include <ctime>

using namespace std;

const int MAX=1000;
double A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

void inicializar()
{
	srand (time(NULL));
	for(int i=0; i<MAX; i++)
		for(int j=0; j<MAX; j++)
		{
			A[i][j]=rand() % 100;
			B[i][j]=rand() % 100;
		}
}


void multmat6()
{
	unsigned t0, t1;
	double BlockS=50;
    	for(int i=0; i<MAX; ++i)
 	   	for(int j=0; j<MAX; ++j)
			C[i][j]=0;
			
	t0=clock();
	for(int i1=0; i1<MAX ; i1+=BlockS)
		for(int j1=0; j1<MAX; j1+=BlockS)
			for(int k1=0; k1<MAX; k1+=BlockS)
				for(int i=i1; i<i1+BlockS&&i<MAX; i++)
					for(int j=j1; j<j1+BlockS&&j<MAX; j++)
						for(int k=k1; k<k1+BlockS&&k<MAX; k++)
							C[i][j]=C[i][j]+A[i][k]*B[k][j];
	t1=clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout<<"Matriz de "<<MAX<<" x "<<MAX<<" - 6 bucles: "<<time<<endl;
}

int main()
{
	inicializar();
	multmat6();
}
