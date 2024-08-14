#include <iostream>
#include <vector>
#include <cmath>

#define rep(i,a,b) for(int i = a; a < b; a++)

using namespace std;

int N,E,C;
int P,Q;
int F;
int D;

int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int g = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return g;
}

unsigned long long modExp(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}


void PQ() 
{ 
    int n = N;
    int aux=0;

    if (n % 2 == 0) 
    { 
        aux = 2;
        n=n/2;
    } 

    if(aux==0){
    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        if (n % i == 0) 
        { 
            aux = i; 
            n = n/i;
            break; 
        }
    }
    } 
    P = aux;
    Q = n;
} 

int solve(){
    PQ();
    F = (P-1)*(Q-1);

    int x, y;
    int g = gcd(E, F, x, y);
    D = (x % F + F) % F;

    return modExp(C,D,N);
}


int main(){
    cin>>N>>E>>C;
    cout<<solve()<<endl;
}
