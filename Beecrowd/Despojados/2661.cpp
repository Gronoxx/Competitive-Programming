#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>

using namespace std;

long int fact(long int n){
    long int result=n;
    if(n==0)
    return 1;
    while(n>1){
    result=result * (n-1);
    n--;
    }
    return result;
}

vector<long int> Fatoração (long int n) 
{ 
    vector<long int> result;
    while (n % 2 == 0) { 
        result.push_back(2); 
        n = n/2; 
    } 
    for (int i = 3; i <= sqrt(n); i = i + 2) { 
        while (n % i == 0) { 
            result.push_back(i);
            n = n/i; 
        } 
    } 
    if (n > 2) 
        result.push_back(n); 
    return result;
} 

void ElementosUnicos(vector<long int>& v) {
    unordered_set<long int> s;
    v.erase(remove_if(v.begin(), v.end(), [&](int num) {
        return !s.insert(num).second;
    }), v.end());
}

int Despojado(long int n){
        vector<long int> fat = Fatoração(n);
        ElementosUnicos(fat);
        int result=0;
        int m = fat.size();
        for(int i=1;i<=m;i++){
            result+=fact(m)/(fact(i)*fact(m-i));
        }

    return result - m;
}

int main(){
    long int n;
    cin>>n;
    cout<<Despojado(n)<<endl;
    return 0;
}
