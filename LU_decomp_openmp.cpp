#include <iostream>
#include <random>
#include <boost/chrono.hpp>
#include <omp.h>

void dis(int n, double** upper, double** lower, double** A) {
    int i, j, k, m1, m2;
#pragma omp parallel for shared(A, lower, upper, n) private(i, j, k, m1, m2)
    for (i = 0; i < n; i++) {
        for (k = i; k < n; k++) {
            m1 = 0;
            for (j = 0; j < i; j++) {
                m1 += (lower[i][j] * upper[j][k]);
            }
            upper[i][k] = A[i][k] - m1;
        }

#pragma omp parallel for shared(A, lower, upper, n) private(j, k, m2)
        for (k = i; k < n; k++) {
            if (i == k)
                lower[i][i] = 1;
            else {
                m2 = 0;
                for (j = 0; j < i; j++) {
                    m2 += (lower[k][j] * upper[j][i]);
                }
                lower[k][i] = (A[k][i] - m2) / upper[i][i];
            }
        }
    }
}

double calc(int n, double** a) {
    double p = 1;
    for (int i = 0; i < n; i++) {
        p *= a[i][i];
    }
    return p;
}

int main() {
    boost::chrono::system_clock::time_point before = boost::chrono::system_clock::now();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);

    for (int n = 1000; n <= 100000; n *= 10) {
        double** A = new double* [n];
        double** lower = new double* [n];
        double** upper = new double* [n];
        for (int i = 0; i < n; i++) {
            A[i] = new double[n];
            lower[i] = new double[n];
            upper[i] = new double[n];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = dis(gen);
            }
        }

        dis(n, upper, lower, A);

        std::cout << "The determinant of the matrix of size " << n << "x" << n << " A is: " << std::endl;
        std::cout << calc(n, upper) << std::endl;
        boost::chrono::system_clock::time_point now = boost::chrono::system_clock::now();
        boost::chrono::nanoseconds t = boost::chrono::duration_cast<boost::chrono::nanoseconds>(now - before);
        std::cout << "took: " << t.count() << " nanoseconds" << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "" << std::endl;

        for (int i = 0; i < n; i++) {
            delete[] A[i];
            delete[] lower[i];
            delete[] upper[i];
        }
        delete[] A;
        delete[] lower;
        delete[] upper;
    }
    return 0;
}
