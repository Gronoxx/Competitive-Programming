#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define ll  long long
#define point  pair<ll, ll>

ll calculateSquaredDistance(const point &a, const point &b) {
    return (b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second);
}

int main() {

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<point> pontos(n);
        for (auto &p : pontos) {
            cin >> p.first >> p.second;
        }

        ll total = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<ll, ll> dis;
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    ll distance = calculateSquaredDistance(pontos[i], pontos[j]);
                    dis[distance]++;
                }
            }

            for (const auto &entry : dis) {
                ll count = entry.second;
                total += count * (count - 1) / 2;
            }
        }

        cout << total << '\n';
    }

    return 0;
}
