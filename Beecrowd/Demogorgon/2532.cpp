#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits.h>
#define INF 0x3f3f3f3f

using namespace std;

struct Feitico{
    int mana, dano;
    Feitico(const int mana, int dano) : mana(mana), dano(dano) {}
};


int mochila(vector<Feitico> feiticos, int sum_dano, int target ){
    vector<vector<int>> M(feiticos.size() + 1, vector<int>(sum_dano + 1, INF));
    M[0][0] = 0;

    for(int i = 1; i <= feiticos.size(); i++){
        for(int j = 0; j <= sum_dano; j++){
            if(feiticos[i - 1].dano > j){
                M[i][j] = M[i - 1][j];
            }else{
                M[i][j] = min(M[i - 1][j], (M[i - 1][j - feiticos[i - 1].dano] + feiticos[i - 1].mana));
            }
        }
    }

    vector<int> possibilidades(M[feiticos.size()].begin() + target, M[feiticos.size()].end());

    int minimo = 2 * INF;
    for(int i = 0; i < possibilidades.size(); i++){
        if(possibilidades[i] < minimo){
            minimo = possibilidades[i];
        }
    }

    return minimo;
}





int main(){
    int N;
    while(cin>>N){
        int P;
        cin>>P;
        vector<Feitico> feiticos;
        int sum_dano = 0;
        for(int i=0;i<N;i++){
            int dano,mana;
            cin>>dano>>mana;
            sum_dano += dano;
            feiticos.push_back(Feitico(mana,dano));
        }
        if(sum_dano<P){
            cout<<-1<<endl;
            continue;
        }
        cout<<mochila(feiticos,sum_dano,P)<<endl;
    }


    return 0;
}
