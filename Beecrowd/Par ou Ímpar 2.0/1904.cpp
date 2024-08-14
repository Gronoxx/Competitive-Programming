#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>

#define rep(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int A, B;

int Lucas(int n, int k) {

    while (n > 0 || k > 0) {

        if ((n % 2) < (k % 2)) {
            return 0;
        }

        n /= 2;
        k /= 2;
    }
 
    return 1;
}



int main(){

    cin >> A >> B;
    
    if(A>B){
        int temp =B;
        B=A;
        A=temp;
    }
    
    int num_fact = abs(A-B);

    if (num_fact == 0) {
        cout << "?" << endl;
        return 0;
    }

    vector<bool> prime(B + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i <= sqrt(B); ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= B; j += i) {
                prime[j] = false;
            }
        }
    }

    vector<int> all_primes;
    rep(i, A, B + 1) {
        if (prime[i]) {
            all_primes.push_back(i);
        }
    }

    int n = all_primes.size();
    int a = n + num_fact - 1, b = num_fact;
    int r = Lucas(a,b);
    if(r==0)
    cout<<"Bob"<<endl;
    else
    cout<<"Alice"<<endl;

    return 0;

}
