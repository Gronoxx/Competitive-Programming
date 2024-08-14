#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000;

typedef vector<vector<unsigned long long>> Matrix;

Matrix multiply(Matrix a, Matrix b) {
    Matrix c(3, vector<unsigned long long>(3, 0));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return c;
}

Matrix matrix_power(Matrix base, unsigned long long exp) {
    Matrix result = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = multiply(result, base);
        }
        base = multiply(base, base);
        exp /= 2;
    }
    return result;
}

unsigned long long count_ways(unsigned long long N, unsigned long long K, unsigned long long L) {
    Matrix A = { {K % MOD, L% MOD, 0}, {1, 0, 0}, {0, 1, 0} };

    vector<unsigned long long> initial = { 0, 0, 1 }; 

    Matrix An = matrix_power(A, N / 5);

    unsigned long long result = 0;
    for (int i = 0; i < 3; i++) {
        result = (result + An[0][i] * initial[2 - i]) % MOD;
    }

    return result;
}

int main() {
    unsigned long long N, K, L;

    while (cin >> N >> K >> L) {
        unsigned long long result = count_ways(N, K, L);
        printf("%06lld\n", result);
    }

    return 0;
}
