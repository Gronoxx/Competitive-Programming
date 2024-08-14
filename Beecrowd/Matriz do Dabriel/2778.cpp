#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXm = 101;
const int MAXx = 20;
const int NAO_RESOLVIDA =  0x3f3f3f3f, SEM_SOLUCAO = NAO_RESOLVIDA + 100;

int N,M,X,Y;
int matrix[MAXm][MAXm];
int dp[MAXm][MAXm][MAXx+1][MAXx+1][3];


int fun(int i, int j, int x, int y, int l) {
if(i == N || j < 0 || j == M)
     return SEM_SOLUCAO;

int value = matrix[i][j];

if(value == 0) 
    x--; 
else if(value < 0) 
    y--;

if(x < 0 || y < 0) 
    return SEM_SOLUCAO;

if(dp[i][j][x][y][l] != NAO_RESOLVIDA) 
    return dp[i][j][x][y][l];

if(i == N-1 and j == M-1) 
    return value;

int a = SEM_SOLUCAO, b = SEM_SOLUCAO, c = SEM_SOLUCAO;

    // 0 baixo, 1 direita, 2 esquerda
    if (l != 2)
        a = fun( i, j + 1, x, y, 1);
    if (l != 1)
        b = fun(i, j - 1, x, y, 2);
    c = fun(i + 1, j, x, y, 0);

    int minimo = min({a, b, c});
    if(minimo == SEM_SOLUCAO)
    dp[i][j][x][y][l] = SEM_SOLUCAO;
    else
    dp[i][j][x][y][l] = value + minimo;

    return dp[i][j][x][y][l];

}




int main() {
    while (cin >> N >> M >> X >> Y) {
        memset(dp, NAO_RESOLVIDA, sizeof dp);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> matrix[i][j];
            }
        }
        
        int result = fun(0, 0, X, Y, 0);
        
        if(result > 1e6)
            cout << "Impossivel" << endl;
        else 
        cout << result << endl;
    }

    return 0;
}
