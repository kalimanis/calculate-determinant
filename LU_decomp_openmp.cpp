
#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <boost/chrono.hpp>
using namespace std;

void dis(int n, double **upper, double **lower, double **A){

	int i,j,k,m1,m2;
	for(i=0;i<n;i++){
		//upper
		#pragma omp parallel for shared(A,lower,upper,n,i) private(k,m1)
		for(k=i;k<n;k++){
			m1=0;
			for(j=0;j<i;j++){
				m1+=(lower[i][j]*upper[j][k]);
			}
			upper[i][k]=A[i][k]-m1;
		}
		//lower
		#pragma omp parallel for shared(A,lower,upper,n,i) private(k,m2)
		for(k=i;k<n;k++){
			if(i==k)
				lower[i][i]=1;
			else{
				m2=0;
				for(j=0;j<i;j++){
					m2+=(lower[k][j]*upper[j][i]);
				}
				lower[k][i]=(A[k][i]-m2)/upper[i][i];
			}
		}
	}
}

double calc(int n, double **a){
	int i,j;
	double p=1;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j)
				p=p*a[i][j];
		}
	}
	return p;
}

int main(){
	boost::chrono::system_clock::time_point before = boost::chrono::system_clock::now();
	//orimos metablhtwn
	for(int n=1000;n<=100000;n=n*10){

	int i,j,k,m1,m2;
	double **A;
	double **lower;
	double **upper;
	A=new double*[n];
	upper=new double*[n];
	lower=new double*[n];
	for (i=0;i<n;i++){
	        A[i]=new double[n];
		lower[i]=new double[n];
		upper[i]=new double[n];
	}

	
	//o pinakas a 8a exei times sto diasthma [-1,1]
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			A[i][j]=rand()%3-1;
		}
	}

	dis(n,upper,lower,A);
	
	cout<<"h orizousa tou pinaka diastashs "<<n<<"x"<<n<<" A einai: "<<endl;

	cout<<calc(n,upper)<<endl;
	boost::chrono::system_clock::time_point now = boost::chrono::system_clock::now();
	boost::chrono::nanoseconds t = boost::chrono::duration_cast<boost::chrono::nanoseconds>(now-before);
	cout << "took: " << t.count() << " nanoseconds"<<endl;
	cout<<"=============================="<<endl;
	cout<<""<<endl;

	}
	return 0;
}
