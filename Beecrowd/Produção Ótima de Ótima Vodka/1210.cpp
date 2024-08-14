#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
#define repn(i,a,b) for(int i=a;i>=b;--i)
#define repr(i,a,b) for(int i=a;i<=b;++i)


const int NV = 0x3f3f3f3f;

int N,M,I,P;

int solve(int i,int n,vector<int> &custos, vector<int> &vendas, vector<vector<int>> &dp){
    if(n == N)
    return 0;
    
    if(i==M)
    return dp[i][n] = custos[0] + (solve(1, n+1,custos,vendas,dp) - vendas[i] + P);
    
    if(dp[i][n]!=NV)
    return dp[i][n];
    
    int a = custos[i] + solve(i+1,n+1,custos,vendas,dp), b =custos[0] + (solve(1, n+1,custos,vendas,dp) - vendas[i] + P);
    
    if(a<b){
    return dp[i][n] = a;
    }
    
    return dp[i][n] = b;  
}   



int main(){

    while(cin>>N>>I>>M>>P){
        
        N++;
        
        vector<vector<int>> dp(M+2, vector<int>(N+2,NV));        
        vector<int> custos(M,0),vendas(M+1);
        
        rep(i,0,M) {int aux; cin>>aux; custos[i] = (aux);}
        repr(i,1,M) {int aux; cin>>aux; vendas[i] = (aux);}
        
        cout<<solve(I,1,custos,vendas,dp)<<endl;
        
        int n=1,i=I;
        vector<int>resposta;
        while(n<N){
            if(i==M){
            resposta.push_back(n);
            i=1;
            }
            else if(custos[i] + dp[i+1][n+1]< custos[0] + dp[1][n+1] - vendas[i] + P)
            i++;
            else{
            resposta.push_back(n);
            i=1;
            }
            n++;
        }
        if(resposta.size()==0)
        cout<<0;
        else{
        for(int k=0;k<resposta.size()-1;k++){
            cout<<resposta[k]<<" ";
        }
        cout<<resposta[resposta.size()-1];
        }
        cout<<endl;
    }


    return 0;
}
