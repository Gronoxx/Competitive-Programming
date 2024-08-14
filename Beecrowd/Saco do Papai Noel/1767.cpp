#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Brinquedo{
    int qt,peso;
    Brinquedo(int q, int p) : qt(q), peso(p) {}
};

bool compareByPeso(const Brinquedo& a, const Brinquedo& b) {
    return a.peso < b.peso; // Or use '>' for descending order
}

struct Celula{
    int peso=0;
    int qntd=0;
    int qntd_p=0;
};

int main(){

    int n;
    cin>>n;
    for(int t=0;t<n;t++){
        int pac;
        cin>>pac;
        vector<Brinquedo> b;
        for(int p=0;p<pac;p++){
            int qt,peso;
            cin>>qt>>peso;
            Brinquedo aux(qt,peso);
            b.push_back(aux);
        }
        sort(b.begin(), b.end(), compareByPeso);
        vector<vector<Celula>> M (b.size()+1,vector<Celula>(51));
        for(int r = 1; r<=b.size();r++){
            for(int c = 0;c<51;c++){
                if(b[r-1].peso<=c && M[r-1][c-b[r-1].peso].qntd+b[r-1].qt>M[r-1][c].qntd){
                M[r][c].qntd = M[r-1][c-b[r-1].peso].qntd+b[r-1].qt;
                M[r][c].peso = M[r-1][c-b[r-1].peso].peso+b[r-1].peso;
                M[r][c].qntd_p = M[r-1][c-b[r-1].peso].qntd_p + 1;
                }
                else{
                M[r][c] = M[r-1][c];
                }
            }
        }
        cout<<M[b.size()][50].qntd<<" brinquedos"<<endl<<"Peso: "<<M[b.size()][50].peso<<" kg"<<endl<<"sobra(m) "<<pac-M[b.size()][50].qntd_p<<" pacote(s)"<<endl<<endl; 
                 
    }

    return 0;
}
