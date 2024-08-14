#include <iostream>

using namespace std;

const int MOD = 1000000007;

unsigned long long Func(unsigned long long n) {
    unsigned long long result = 0;
    unsigned long long casa = 1;
    
    while (casa <= n) {
        unsigned long long rc = n / (casa * 10) * casa;
        unsigned long long cd = (n / casa) % 10;
        unsigned long long hn = n % casa;

        result += rc * 45;
        result += cd * (cd - 1) / 2 * casa;
        result += cd * (hn + 1);

        result %= MOD;
        casa *= 10;
    }

    return result;
}

unsigned long long Sum(unsigned long long L, unsigned long long R) {
    return (Func(R) - Func(L - 1)) % MOD;
}

int main() {
    unsigned long long L, R;
    
    while (cin >> L >> R) {
        cout << Sum(L, R) << endl;
    }

    return 0;
}
