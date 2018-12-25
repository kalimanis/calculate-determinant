#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <boost/chrono.hpp>
#include <time.h>
using namespace std;


double gin(int k, double **mat)
{
	double p=1;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(i==j)
			{
				p=p*mat[i][j];
			}
		}
	}
		for(int i=0;i<k;i++){
			delete[] mat[i];
		}
		delete[] mat;
	return p;
}
int main(){

	boost::chrono::system_clock::time_point before = boost::chrono::system_clock::now();

	for(int n=10;n<=50;n=n+5){
		int i,j;
		cout<<"h diastash tou pinaka einai: "<<n<<"x"<<n<<endl;
		double **pt1;
		double **lower;
		double **upper;


		pt1=new double*[n];
		lower=new double*[n];
		upper=new double*[n];
	 	for (i=0;i<n;i++){
	        	pt1[i]=new double[n];
			lower[i]=new double[n];
			upper[i]=new double[n];
		}

		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				pt1[i][j]=rand()%3-1;
			}
		}

		cout<<""<<endl;

		//paragontopoihsh tou pinaka pt1 se LU dhladh pt1=LU,det(pt1)=detL*detU
		//opou detL kai detU einai to ginomeno twn stoixeiwn ths kurias diagwniou
		for(i=0;i<n;i++){
			//Upper
			for(int k=i;k<n;k++){
				int sum=0;
				for(j=0;j<i;j++){
					sum+=(lower[i][j]*upper[j][k]);
				}
				upper[i][k]=pt1[i][k]-sum;
			}
			for(int k=i;k<n;k++){
				if(i==k)
					lower[i][i]=1;
				else{
					int sum=0;
					for(j=0;j<i;j++){
						sum+=(lower[k][j]*upper[j][i]);
					}
					lower[k][i]=(pt1[k][i]-sum)/upper[i][i];
				}
			}
		}


		cout<<"h orizousa tou pinaka A, opou A=LU einai: "<<gin(n,upper)<<endl;
		boost::chrono::system_clock::time_point now = boost::chrono::system_clock::now(); 
		boost::chrono::nanoseconds t = boost::chrono::duration_cast<boost::chrono::nanoseconds>(now-before);

		cout << "took: " << t.count() << " nanoseconds"<<endl;
		cout<<"=============================="<<endl;

		cout<<""<<endl;
		for(i=0;i<n;i++){
			delete[] pt1[i];
		}
		delete[] pt1;
	}

	return 0;
}

