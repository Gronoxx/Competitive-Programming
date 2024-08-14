#include <iostream>
#include <vector>

#define rep(i,a,b) for(int i =a; i<b; i++)

using namespace std;

typedef long long ll;
const int MOD = 13371337;

struct Matrix {
    vector<vector<ll>> mat;
    int n;

    Matrix(int size) : n(size) {
        mat.resize(n, vector<ll>(n,0));
    }

    Matrix operator*(const Matrix& other) const {
    Matrix product(n);
    rep(i, 0, n) {
        rep(j, 0, n) {
            rep(k, 0, n) {
                product.mat[i][j] = (product.mat[i][j] + (mat[i][k] * other.mat[k][j]) % MOD) % MOD;
            }
        }
    }
    return product;
}

vector<ll> operator*(const vector<ll>& vec) const {
    vector<ll> result(n, 0);
    rep(i, 0, n) {
        rep(j, 0, n) {
            result[i] = (result[i] + (mat[i][j] * vec[j]) % MOD) % MOD;
        }
    }
    return result;
}

    static Matrix identity(int size) {
        Matrix id(size);
        rep(i, 0, size) {
            id.mat[i][i] = 1;
        }
        return id;
    }

    Matrix pow(ll exp) const {
        Matrix result = identity(n);
        Matrix base = *this;

        while (exp > 0) {
            if (exp % 2 == 1) {
                result = result * base;
            }
            base = base * base;
            exp /= 2;
        }

        return result;
    }
};

int main() {
    int N;
    while (cin >> N) {
        if(N==0)
        break;
        vector<ll> v(4, 0); // v[0] dia anterior v[5] dia atual
        rep(i, 1, 5) {
            cin >> v[i];
        }

        if (N <= 4) {
            ll result = 0;
            rep(i, 1, N + 1) {
                result += v[i];
            }
            cout << result << endl;
        } else {
            Matrix T(4);
            T.mat = {
                {0, 1, 0, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 1},
                {1, 1, 1, 1},
            };

            vector<ll> initial = {v[1], v[2], v[3], v[4]};

            T = T.pow(N - 4);
            vector<ll> result = T * initial;

            cout << (result[0]+result[1]+result[2]+result[3])%MOD << endl;
        }
    }

    return 0;
}
