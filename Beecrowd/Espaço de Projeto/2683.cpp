#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

struct Edge{
    int i,f,c;
};

bool CompareEdge (const Edge& e1, const Edge& e2) {
        // Compare based on 'dis'
        return e1.c > e2.c;
}

bool CompareEdge2 (const Edge& e1, const Edge& e2) {
        // Compare based on 'dis'
        return e1.c < e2.c;
}

int Find(int p1,vector<int> &id_vertice){
    while(id_vertice[p1]!=p1){
        p1=id_vertice[id_vertice[p1]];
    }
    return p1;
}

void Union(int pai_1, int pai_2, vector<int> &id_vertice,vector<int> &tamanho_id){
    //Descobre o maior conjunto
    if(tamanho_id[pai_1]> tamanho_id[pai_2]){
        id_vertice[pai_2] = pai_1; // o pai do conjunto menor vira o pai do conjunto maior fazendo a fusão
        tamanho_id[pai_1] = tamanho_id[pai_1] + tamanho_id[pai_2]; //o tamanho do conjunto maior cresce
        tamanho_id[pai_2] = 0; // o do menor zera
    }
    else{
        id_vertice[pai_1] = pai_2;
        tamanho_id[pai_2] = tamanho_id[pai_1] + tamanho_id[pai_2];
        tamanho_id[pai_1] = 0;
    }
}



int main(){
int n;
cin>>n;
vector<Edge> arestas;
int num_vertices=0;

//Cria todas as arestas e aloca no vetor
for(int i=0;i<n;i++){
    int u,v,w;
    cin>>u>>v>>w;
    num_vertices = max(max(num_vertices,u),v);
    Edge aux;
    aux.i = u-1;
    aux.f = v-1;
    aux.c = w; 
    Edge aux1;
    aux1.i = v-1;
    aux1.f = u-1;
    aux1.c = w;
    arestas.push_back(aux);
    arestas.push_back(aux1);    
}
//Cada vertice no seu próprio conjunto 
vector<int> id_vertice(num_vertices);
vector<int> tamanho_id(num_vertices);
for(int i=0;i<num_vertices;i++){
    id_vertice[i]=i;
    tamanho_id[i]=1;
}
//Ordena as arestas
sort(arestas.begin(),arestas.end(),CompareEdge);

int custo_total=0;
for(int i=0;i<arestas.size();i++){
    int pai_1 = Find(arestas[i].i,id_vertice);
    int pai_2 = Find(arestas[i].f,id_vertice);
    if(pai_1!=pai_2){
    Union(pai_1,pai_2,id_vertice,tamanho_id);
    custo_total+=arestas[i].c;
    }
}
cout<<custo_total<<endl;

for(int i=0;i<num_vertices;i++){
    id_vertice[i]=i;
    tamanho_id[i]=1;
}

//Ordena as arestas
sort(arestas.begin(),arestas.end(),CompareEdge2);

custo_total=0;
for(int i=0;i<arestas.size();i++){
    int pai_1 = Find(arestas[i].i,id_vertice);
    int pai_2 = Find(arestas[i].f,id_vertice);
    if(pai_1!=pai_2){
    Union(pai_1,pai_2,id_vertice,tamanho_id);
    custo_total+=arestas[i].c;
    }
}
cout<<custo_total<<endl;





return 0;
}
