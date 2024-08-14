#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iomanip>

using namespace std;

double Func(int n,int k,int pulos_restantes,int qst_atual,vector<int> &premios,vector<double> &probabilidades,vector<vector<double>> &M){
    
    if(qst_atual==n)
    return 0;
    
    if (M[pulos_restantes][qst_atual]!=-1)
    return M[pulos_restantes][qst_atual];

    double prob_pula = 1.00;
    double prob_faz = probabilidades[qst_atual];

    if(pulos_restantes>0){
        double result = max(Func(n,k,pulos_restantes-1,qst_atual+1,premios,probabilidades,M) * prob_pula + premios[qst_atual] * prob_pula, Func(n,k,pulos_restantes,qst_atual+1,premios,probabilidades,M) * prob_faz + premios[qst_atual] * prob_faz);
        M[pulos_restantes][qst_atual]= result;
    }
    else{
        double result = Func(n,k,pulos_restantes,qst_atual+1,premios,probabilidades,M) * prob_faz + premios[qst_atual] * prob_faz;
        M[pulos_restantes][qst_atual]= result;
    }

    return M[pulos_restantes][qst_atual];
}

int main(){

    int n,k;
    while(cin>>n>>k){
        vector<int> premios;
        vector<double>probabilidades;
        for(int i=0;i<n;i++){
        int aux;
        cin>>aux;
        premios.push_back(aux);
        }
        for(int i=0;i<n;i++){
        double aux;
        cin>>aux;
        aux= aux/100.00;
        probabilidades.push_back(aux);
        }
        vector<vector<double>> M (k+1,vector<double> (n,-1));
        cout<<fixed<<setprecision(2)<<Func(n,k,k,0,premios,probabilidades,M)<<endl;
    }

    return 0;
}
