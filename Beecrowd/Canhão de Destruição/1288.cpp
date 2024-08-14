#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Objeto{
    int peso,valor;
    Objeto(const int peso, int valor) : peso(peso), valor(valor) {}
};

bool compararPeso(const Objeto& obj1, const Objeto& obj2) {
    return obj1.peso < obj2.peso;
}

int mochila(vector<Objeto> &objetos,int peso_mochila){
    vector<vector<int>> M (objetos.size(),vector<int> (peso_mochila+1));
    for(int i=0;i<peso_mochila+1;i++){
        if(i<objetos[0].peso)
        M[0][i]= 0;
        else
        M[0][i] = objetos[0].valor;
    }
    for(int i=1;i<objetos.size();i++){
        for(int j=0;j<peso_mochila+1;j++){
            if(j-objetos[i].peso>=0) //se couber o objeto na mochila
            M[i][j] = max(M[i-1][j-objetos[i].peso] + objetos[i].valor, M[i-1][j]);
            else
            M[i][j] = M[i-1][j];
        }
    }
    return M[objetos.size()-1][peso_mochila];
}


int main(){
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int n;
        cin>>n;
        vector<Objeto> objetos;
        for(int i=0;i<n;i++){
            int peso,valor;
            cin>>valor>>peso;
            objetos.push_back(Objeto(peso,valor));
        }
        int peso_mochila;
        cin>>peso_mochila;
        int R;
        cin>>R;
        sort(objetos.begin(),objetos.end(), compararPeso);
        int max_value = mochila(objetos,peso_mochila);
        if(max_value>=R)
        cout<<"Missao completada com sucesso"<<endl;
        else
        cout<<"Falha na missao"<<endl;

    }


    return 0;
}
