#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <unordered_set>


using namespace std;

void ElementosUnicos(vector<int>& v) {
    unordered_set<int> s;
    v.erase(remove_if(v.begin(), v.end(), [&](int num) {
        return !s.insert(num).second;
    }), v.end());
}

int main(){

    int M,N;
    while(cin>>M){
    cin>>N;
    if(M==0 && N==0)
    break;
    M=M*100; //passo pra centimentros
    N=N*100; //passo pra centimentros
    int L;
    cin>>L;
    int K;
    cin>>K;
    vector<int> entrada(K);
    unordered_map <int,int> mapa;
    for(int i=0;i<K;i++){
        cin>>entrada[i];
        entrada[i] = entrada[i] * 100; //armazenamos no vetor
        mapa[entrada[i]]++; //qntd no mapa
    }
    ElementosUnicos(entrada); //apenas os únicos
    sort(entrada.begin(),entrada.end());
    int RM1 = mapa[M];
    int RM2 =0;
    for(int i=0;i<entrada.size();i++){
        if(entrada[i]==M)
        continue;
        RM2+=min(mapa[entrada[i]],mapa[M-entrada[i]]);
    }
    RM2=RM2/2;

    int RN1 = mapa[N];
    int RN2 =0;
    for(int i=0;i<entrada.size();i++){
        if(entrada[i]==N)
        continue;
        RN2+=min(mapa[entrada[i]],mapa[N-entrada[i]]);
    }
    RN2=RN2/2;

    int resposta = INT_MAX;
    if(M%L == 0 && M/L <= (RN1+RN2)){
            int usadas = M/L;
            if(RN1 < usadas)RN1 += (usadas - RN1)*2;
            else if(RN1 > usadas)RN1 = usadas;
            resposta = min(resposta,RN1);
        }
    if(N%L == 0 && N/L <= (RM1+RM2)){
            int usadas = N/L;
            if(RM1 < usadas)RM1 += (usadas - RM1)*2;
            else if(RM1 > usadas)RM1 = usadas;
            resposta = min(resposta,RM1);
        }
        if(resposta == INT_MAX)
        cout<<"impossivel"<<endl;
        else
        cout<<resposta<<endl;
    }
    


    return 0;
}
