#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,k;
    while(cin>>n>>k){
        if(n==0 && k==0)
        break;
        vector<int> entrada;
        for(int i=0;i<n;i++){
            int aux;
            cin>>aux;
            entrada.push_back(aux);
        }
        vector<vector<long long>> M(n,vector<long long> (n));
        //i = numero sendo analisado
        //j tamanho da subsequencia
        for(int i=0;i<n;i++){
            M[i][0]=1;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=1; j<n; j++){
                for(int l=i+1;l<n;l++){ //olhamos para todos a frente de i
                    if(entrada[l]>entrada[i]){
                        M[i][j] += M[l][j-1];
                    }
                }
            }
        }
        long long result=0;
        for(int i=0;i<n;i++){
        result+= M[i][k-1];
        }
        cout<<result<<endl;
    }



    return 0;
}
