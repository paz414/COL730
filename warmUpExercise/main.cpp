#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <iomanip>
using namespace std;
void multiply_matrices1(const vector<vector<int> >& A, 
                       const vector<vector<int> >& B, 
                       vector<vector<int> >& C, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
             int s = 0;
            for(int k = 0; k < n; k++) {
                s += A[i][k] * B[k][j];
            }
            C[i][j] = s;
        }
    }
}
void multiply_matrices2(const vector<vector<int> >& A, 
                       const vector<vector<int> >& B, 
                       vector<vector<int> >& C, int n) {
    for(int i = 0; i < n; i++) {
        for(int k = 0; k < n; k++) {
             int s = 0;
            for(int j= 0; j < n; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void multiply_matrices3(const vector<vector<int> >& A, 
                       const vector<vector<int> >& B, 
                       vector<vector<int> >& C, int n) {
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++) {
             int s = 0;
            for(int k = 0; k < n; k++) {
                s += A[i][k] * B[k][j];
            }
            C[i][j] = s;
        }
    }
}
void multiply_matrices4(const vector<vector<int> >& A, 
                       const vector<vector<int> >& B, 
                       vector<vector<int> >& C, int n) {
    for(int j = 0; j < n; j++) {
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void multiply_matrices5(const vector<vector<int> >& A, 
                       const vector<vector<int> >& B, 
                       vector<vector<int> >& C, int n) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void multiply_matrices6(const vector<vector<int> >& A, 
                       const vector<vector<int> >& B, 
                       vector<vector<int> >& C, int n) {
     for(int k = 0; k < n; k++) {
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < n; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
vector<vector<int> > generate_matrix(int n){
    vector<vector<int > > matrix(n, vector<int>(n));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 10);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matrix[i][j] = dis(gen);
        }
    }
    return matrix;
}
double measureTime(int n, void (*matrixMultFunc)(const vector<vector<int> >&, const vector<vector<int> >&, vector<vector<int> >&, int)){

    auto A = generate_matrix(n);
    auto B = generate_matrix(n);
    auto C = vector<vector<int> >(n, vector<int>(n, 0));

    auto start = chrono::high_resolution_clock::now();
    matrixMultFunc(A, B, C, n);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double>(end - start).count();
}

int main() {
    int nn =  800;
    for (int n = 50; n <= nn; n += 50) {
        double timeIJK = measureTime(n, multiply_matrices1);
        double timeIKJ = measureTime(n, multiply_matrices2);
        double timeJIK = measureTime(n, multiply_matrices3);
        double timeJKI = measureTime(n, multiply_matrices4);
        double timeKIJ = measureTime(n, multiply_matrices5);
        double timeKJI = measureTime(n, multiply_matrices6);

        cout << "Size: " << n 
             << ", IJK: " << fixed << setprecision(6) << timeIJK
             << ", IKJ: " << timeIKJ
             << ", JIK: " << timeJIK
             << ", JKI: " << timeJKI
             << ", KIJ: " << timeKIJ
             << ", KJI: " << timeKJI << endl;
    }
    return 0;
}
