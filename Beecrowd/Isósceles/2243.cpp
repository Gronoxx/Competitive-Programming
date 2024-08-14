#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int aux;
        cin>>aux;
        v.push_back(aux);
    }
    //Varredura e -> d
    vector <int> e(n);
    for(int i=0;i<n;i++){
        if(i==0)
        e[i] = 1;
        else
        e[i] = min(v[i],e[i-1]+1);
    }

    //Varredura d -> e
    vector <int> d(n);
    for(int i=n-1;i>=0;i--){
        if(i==n-1)
        d[i] = 1;
        else
        d[i] = min(v[i],d[i+1]+1);
    }

    int resultado =0;
    for(int i=0;i<n;i++){
        resultado = max(resultado, min(e[i],d[i]));
    }
    cout<<resultado<<endl;


    return 0;
}
