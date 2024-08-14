#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

#define rep(i,a,b) for(int i=a;i<b;++i)
#define MAX 2000000

using namespace std;


struct Cell{
    int prime=0,expo=0;
    Cell() {}
};

vector<int> ans(MAX+1,0);

void fun(){
    ans[1]=0;

    vector<Cell> v(MAX+1);
    vector<bool> prime (MAX+1,true);
    
    for(int i = 2; i<=sqrt(MAX+1);i++){
        
            if(i==10061)
            cout<<endl;
        
        if(prime[i]==true){

            v[i].prime = i;
            v[i].expo = 1;

            for (int j = i + i; j <= MAX; j += i){
                prime[j] = false;
                
                v[j].prime=i;

                if(v[j/i].prime==i)
                    v[j].expo=v[j/i].expo+1;
                else
                    v[j].expo = 1;
            }
        }
    }

    int total =1;
    vector<int> div (MAX+1);
    div[1] = 1;

    //Primos acima de raiz de n, n sao marcados. Um numero eh composto por no maximo um primo nao marcado

    rep(i, 2, MAX + 1) {

        if(prime[i]){
        div[i] = 2;
        ans[i] = ans[i-1] + 1;
        continue;
        }
        else
        div[i] = (v[i].expo + 1);
        
        div[i] *= div[i / int(pow(v[i].prime, v[i].expo))];


        if(prime[div[i]])
            ans[i] = ans[i - 1] + 1;
        else
            ans[i] = ans[i - 1];
    
    }

    return;
}

int main(){
    fun();
    int N;
    while(cin>>N){
        cout<<ans[N]<<endl;
    }

    return 0;
}
