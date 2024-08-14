#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int R, C, K;
    while (cin >> R >> C >> K) {
        if (R == 0 && C == 0 && K == 0)
            break;

        int result = INT_MAX;
        vector<vector<int>> m(R + 1, vector<int>(C + 1, 0));
        for (int i = 1; i <= R; i++) {
            int line = 0;
            for (int j = 1; j <= C; j++) {
                char aux;
                cin >> aux;
                if (aux == '.')
                    line++;
                if (i == 1)
                    m[i][j] = line;
                else
                    m[i][j] = m[i - 1][j] + line;
            }
        }

        for (int l = 1; l <= C; l++) {
            for (int r = l; r <= C; r++) {
                int u = 1, d = 1;
                while (d <= R) {
                    int current_sum = m[d][r] - m[d][l - 1] - m[u - 1][r] + m[u - 1][l - 1];
                    while (current_sum > K) {
                        int area = (d - u + 1) * (r - l + 1);
                        result = min(result, area);
                        u++;
                        current_sum = m[d][r] - m[d][l - 1] - m[u - 1][r] + m[u - 1][l - 1];
                    }
                    while (current_sum == K) {
                        int area = (d - u + 1) * (r - l + 1);
                        result = min(result, area);
                        u++;
                        current_sum = m[d][r] - m[d][l - 1] - m[u - 1][r] + m[u - 1][l - 1];
                    }
                    d++;
                }
            }
        }
        cout << result << endl;
    }

    return 0;
}
