#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n;
    while(cin>>n){
        if(n==0)
        break;
        vector<int> entrada;
        for(int i=0;i<2*n;i++){
            int aux;
            cin>>aux;
            entrada.push_back(aux);
        }
        vector<vector<int>> M(2*n,vector<int>(2*n));
        for(int i=0;i<2*n;i++){
            for(int j=0;j+i<2*n;j++){
                int f = i + j;
                if (i == 0)
                    M[j][f] = 0;
                else if (i % 2 == 0)
                    M[j][f] = min(M[j + 1][f], M[j][f -1]);
                else{
                    int pe=0,pd=0;
                    if(entrada[j] % 2 == 0)
                    pe++;
                    if(entrada[f] % 2 == 0)
                    pd++;
                    M[j][f] = max(M[j + 1][f] + pe, M[j][f - 1] + pd);
                }
            }
        }
        cout<<M[0][2*n-1]<<endl;
    }



    return 0;
}
