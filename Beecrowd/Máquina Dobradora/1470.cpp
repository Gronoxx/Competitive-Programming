#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

vector<int> Combine(vector<int> A){
    vector<int> result;
    for(int i=0;i<A.size()/2;i++){
        result.push_back(A[i]+A[A.size()-1-i]);
    }
    return result;
}

bool CompareVector(vector<int> A, vector<int> B){
    for(int i=0;i<A.size();i++){
        if(A[i]!=B[i])
        return false;
    }
    return true;
}

bool Fold(vector<int> entrada, vector<int> compare){
    queue<vector<int>> dobraduras;
    dobraduras.push(entrada);
    reverse(entrada.begin(),entrada.end());
    dobraduras.push(entrada);
    while(!dobraduras.empty()){
    vector<int> atual = dobraduras.front();
    dobraduras.pop();
    vector<int> holder = atual;
    if(CompareVector(atual,compare))
    return true;
    for(int i=1;i<atual.size();i++){
        if(atual.size()-min(i,int(atual.size()-i))>=compare.size())//nao precisamos dobrar se for gerar algo menor q a saida, tamanho resultante da dobra é tamanho da fita original - menor pedaço da dobra 
        {   
            double Ts = atual.size();
            if(i==Ts/2){}
            else if(i> Ts/2)
            for(int j=0;j<i-(Ts-i);j++)
            atual.push_back(0);
            else
            for(int j=0;j<Ts-2*i;j++)
            atual.insert(atual.begin(),0);
            dobraduras.push(Combine(atual));
            atual=holder;
        }
    }
    }
    return false;

}

int main(){

int n;
while(cin>>n){
    vector<int> entrada;
    for(int i=0;i<n;i++){
        int aux;
        cin>>aux;
        entrada.push_back(aux);
    }
    vector<int> saida;
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int aux;
        cin>>aux;
        saida.push_back(aux);
    }
    if(Fold(entrada,saida))
    cout<<"S"<<endl;
    else
    cout<<"N"<<endl;
}


return 0;
}
