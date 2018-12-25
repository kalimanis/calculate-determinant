#include <iostream>
#include <math.h>
#include <cstdlib>
#include <time.h>
#include <boost/chrono.hpp>
using namespace std;

double det(int k, double **mat){
    double d=0;
    int c, subi, i, j, subj;
    //double submat[k][k]; //,mat[k][k];
    double **submat;
    submat=new double*[k];
    for (int i=0;i<k;i++)
        submat[i]=new double[k];
    if (k == 2)
    {
        return( (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
    }
    else
    {
        for(c = 0; c < k; c++)
        {
            subi = 0;
            for(i = 1; i < k; i++)
            {
                subj = 0;
                for(j = 0; j < k; j++)
                {
                    if (j == c)
                    {
                        continue;
                    }
                    submat[subi][subj] = mat[i][j];
                    subj++;
                }
                subi++;
            }
        d = d + (pow(-1.0 ,c*1.0) * mat[0][c] * det(k - 1 ,submat));
        }
    }
	delete[] submat;
    return d;
}

int main(){
	boost::chrono::system_clock::time_point before = boost::chrono::system_clock::now();

	for(int n=3;n<=10;n++){
		int i,j;
		cout<<"h diastash tou pinaka einai: "<<n<<"x"<<n<<endl;
		double **pt1;
		pt1=new double*[n];
	 	for (i=0;i<n;i++){
	        	pt1[i]=new double[n];
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				pt1[i][j]=rand()%3-1;
			}
		}
		cout<<"o pinakas A einai:"<<endl;
		for(i=0;i<n;i++){
			cout<<" "<<endl;
			for(j=0;j<n;j++){
				cout<<pt1[i][j]<<" ";
			}
		}

		cout<<""<<endl;
		cout<<"h orizousa tou pinaka A einai: "<<det(n,pt1)<<endl;
		boost::chrono::system_clock::time_point now = boost::chrono::system_clock::now(); 
		boost::chrono::nanoseconds t = boost::chrono::duration_cast<boost::chrono::nanoseconds>(now-before);

		cout << "took: " << t.count() << " nanoseconds"<<endl;
		cout<<"=============================="<<endl;
		for(i=0;i<n;i++){
			delete[] pt1[i];
		}
		delete[] pt1;
	}

	return 0;
}
