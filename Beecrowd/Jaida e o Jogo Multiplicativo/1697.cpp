#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
 
#define MAX 10000000

vector<bool> prime(MAX+1,true);
vector<int> all_primes;


void PC()
{ 
    prime[0] = prime[1] = false;

   for(int i = 2; i<=sqrt(MAX+1);i++){        
        if(prime[i]==true){
            for (int j = i + i; j <= MAX; j += i){
                prime[j] = false;
            }
        }
    }
    for (int p = 2; p <= MAX+1; p++)
        if (prime[p])
            all_primes.push_back(p);
}

int main(){
    PC();
    int t; 
    cin>>t;
    rep(T,0,t){
        int I;
        cin>>I;
        vector<int> input;
        rep(i,0,I){
            int aux;
            cin>>aux;
            input.push_back(aux);
        }

        sort(input.begin(),input.end());
        if(input[0]!=1){
        cout<<0<<endl;
        continue;
        }
        int total_primes=0;
        rep(i,1,input.size()){
            if(input[i]==input[i-1])
            continue;
            if(prime[input[i]]){
                if(all_primes[total_primes] == input[i])
                total_primes++; //confere se o primo encontrado corresponde ao primo que deveria ser
                else
                break;
            }
        }
        //ao chegar aqui sabemos qual o ultimo primo na ordem
        cout<<all_primes[total_primes]-1<<endl;
    
    }
}
