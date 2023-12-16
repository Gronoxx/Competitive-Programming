#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
/*
Para haver solução precisamos pensar da seguinte maneira:
dada uma porta que começa com 1 e possui os switches a e b controlando ela.
Temos duas opções para resolver essa porta:
1. Não ativamos nem a nem b e mantemos 1
2. Ativamos tanto a quanto b e mantemos em 1
OBS: não faz sentidno ativar um switch mais de uma vez pq isso seria equivalente a não ativá-lo
 
Portanto se preto for switch ativado e branco switch não ativado, isso significa que ou a e b são brancos ou ambos são pretos
 
Entretanto, dada uma porta que começa com o valor 0 e possui os switches a e b controlando ela.
Temos duas opções:
1. Ativamos a, mas não ativamos b
2. Ativamos b, mas não ativamos a
 
Portanto, se a or branco, b deve ser preto e se a for preto b deve ser branco.
 
Em outras palavras, uma aresta que começa com valor zero deve possuir os dois nós com cores diferentes e uma aresta com valor 1 deve possuir ambos nós com cores iguais
 
Escrevendo isso em forma booleana:
 
Dada uma porta n, cujos switches são j e k
caso o estado de n = 1,
(j^k)v(~j^~k) //ambos no mesmo estado
utilizando distribuitiva chegamos em
(jv~k)^(kv~j)
Gerando as seguintes implicações:
 
~J->~K
K->J
~K->~J
J->K
 
caso o estado de n = 0, com os mesmos princípios:
~J->K
~K->J
K->~J
J->~K
 
*/
 
 
 
using namespace std;
 
struct Door{
  vector<int> switches_connected; // no maximo dois, os valores dos switches começam em zero
  bool state;
};
 
struct Switch{
    bool state=0;
    vector<int> doors; //valores das portas começam em 1
};
 
struct Vertex{
    int color=0;
    int tempo_a;
    int tempo_f;
    int C;
};
 
 
void DFS(int a,vector<vector<int>> &adj,vector<Vertex> &vertices,int t){
    t++;
    vertices[a].color++;//acessou pintou de cinza
    vertices[a].tempo_a=t; // tempo de abertura quando chega
    for(int i=0;i<adj[a].size();i++){
        if(vertices[adj[a][i]].color==0){
            DFS(adj[a][i],adj,vertices,t);
        }
    }
    t++;
    vertices[a].color++;//terminou pintou de preto
    vertices[a].tempo_f=t; // tempo de fechamento quando acaba
}
void DFS_T(int a,vector<vector<int>> &adj,vector<Vertex> &vertices,int C){
    stack<int> pilha;
    stack<int> CFC;
    pilha.push(a);
    vertices[a].C=C;
    while(!pilha.empty()){
        int v= pilha.top();
        pilha.pop();
        if(vertices[v].color==0){
            vertices[v].C=C;
            vertices[v].color++;
            for(int count=0;count<adj[v].size();count++){
                if(vertices[adj[v][count]].color==0){
                    pilha.push(adj[v][count]);
                }
            }
        }
    }
}
 
 
 
bool Kosaraju_SAT(vector<vector<int>> &adj,vector<vector<int>> &adj_t,vector<Vertex> &vertices,int m){
    
    //DFS NORMAL
    DFS(0,adj,vertices,0);
    //Reset de vertices
    for (int i=0;i<vertices.size();i++){
        vertices[i].color=0;
    }
    std::sort(vertices.begin(), vertices.end(), [](const Vertex& a, const Vertex& b) {
        return a.tempo_f > b.tempo_f;
    });
    //DFS_T
    stack<int> CFC;
    int count=0;
    for (int i=0;i<vertices.size();i++){       
        if(vertices[i].color==0){
        DFS_T(i,adj_t,vertices,count);
        count++;
        }
    }
    //checa se existe x e ~x na msm CFC
    for (int i = 0; i < (vertices.size()/2);i++){
        if(vertices[i].C==vertices[i+m].C)
            return false;
    }
    return true;
}
 
int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<Door>doors(n);
    vector<Switch> switches(m);
    vector<Vertex> vertices (2*m); 
    vector<vector<int>> adj (2*m); // 0 até m postivos m até 2m negativos
    vector<vector<int>> adj_t (2*m);
    for (int i=0;i<n;i++){
        cin>>doors[i].state; // coloca na aresta o estado inicial dela
    }
    for(int i=0;i<m;i++){
        int total;
        cin>>total;
        for(int count=0;count<total;count++){
            int door_atual;
            cin>>door_atual;
            doors[door_atual-1].switches_connected.push_back(i); //coloca em cada aresta os switches que modificam ela
        }
    }
    /*
    caso n=1
    ~J->~K
    K->J
    ~K->~J
    J->K
 
    caso n = 0
    ~J->K
    ~K->J
    K->~J
    J->~K
 
*/
    for (int i=0;i<doors.size();i++){
        int j = doors[i].switches_connected[0];
        int k = doors[i].switches_connected[1];
        if(doors[i].state==1){  
            adj[j+m].push_back(k+m);
            adj[k].push_back(j);
            adj[k+m].push_back(j+m);
            adj[j].push_back(k);
            //GT
            adj_t[k+m].push_back(j+m);
            adj_t[j].push_back(k);
            adj_t[j+m].push_back(k+m);
            adj_t[k].push_back(j);
        }
        else{
            adj[j+m].push_back(k);
            adj[k+m].push_back(j);
            adj[k].push_back(j+m);
            adj[j].push_back(k+m);
            //GT
            adj_t[k+m].push_back(j);
            adj_t[j+m].push_back(k);
            adj_t[j].push_back(k+m);
            adj_t[k].push_back(j+m);
        }
    }
    if(Kosaraju_SAT(adj,adj_t,vertices,m))
    cout<<"YES";
    else
    cout<<"NO";
 
    //
    return 0;
}