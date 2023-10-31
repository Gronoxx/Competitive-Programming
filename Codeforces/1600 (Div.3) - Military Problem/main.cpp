//basicamente usar caminhamento primeiro o no depois filhos da esquierda apra direita por dfs
//faz a dfs a partir do comandante dps se quiser pegar como seria a dfs começando de x pegue a squencia do comandante e faça de x até encontrar um vertice que seja menor do q o ultimo
//para fazer da esquerda para direita deixa toda a lksita de adj ordenada
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Triple{
    int first; // numero vertice
    int second; // size_branco =>indice começo da subarvore
    int third; // size_preto => indice final da subarvore
};
bool compareBranco(const Triple& q1, const Triple& q2) {
        return q1.second < q2.second;
}

bool compareNumero(const Triple& q1, const Triple& q2) {
        return q1.first < q2.first;
}

void DFS(vector<Triple> &standard_spreading, vector<vector<int>> &adj,int v){ //a coloração não é necessária, pois nunca haverá dois caminhos para um vertice
    Triple aux;
    aux.first=v+1;
    int size_branco=standard_spreading.size();
    aux.second=size_branco;
    aux.third=0;
    standard_spreading.push_back(aux); 
    for(int i=0;i<adj[v].size();i++){
        DFS(standard_spreading,adj,adj[v][i]);
    }
    standard_spreading[size_branco].third=standard_spreading.size()-1;
    return;
}

int main(){

    int n;
    int q;
    cin>>n;
    cin>>q;
    vector<vector<int>> adj(n);
    for(int i=1;i<n;i++){
        int aux;
        cin>>aux;
        adj[aux-1].push_back(i); // O vertice 0 recebe o vertice 1, igual ao oficial 1 é comandante do oficial 2 
    }
    vector<Triple> standard_spreading;
    DFS(standard_spreading,adj,0);
    vector<Triple> sorted_vector=standard_spreading;
    sort(standard_spreading.begin(), standard_spreading.end(), compareBranco);
    sort(sorted_vector.begin(), sorted_vector.end(), compareNumero);
    for(int i=0;i<q;i++){
        int v;
        int k;
        cin>>v;
        cin>>k;
        Triple aux = sorted_vector[v-1];
        if(aux.second+(k-1)>aux.third)
        cout<<-1<<endl;
        else
        cout<<standard_spreading[aux.second+(k-1)].first<<endl;
    }

    return 0;
}