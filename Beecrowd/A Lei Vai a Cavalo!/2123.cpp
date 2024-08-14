#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
#define repn(i,a,b) for(int i=a;i>=b;--i)
#define repr(i,a,b) for(int i=a;i<=b;++i)
#define INF 0x3f3f3f3f

int instancia = 0;
int n,m,k;
int result=0;

struct Aresta
{
    int capacidade,fluxo;
    Aresta(){ capacidade= 0; fluxo=0;}
};


vector<vector<Aresta>> M(202, vector<Aresta> (202));
vector<int> level(202,-1);
vector<int> aresta_atual (202);

bool BFS(){
    fill(level.begin(),level.end(),-1);
    level[0]=0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        rep(i,0,202){
            if(M[v][i].capacidade > M[v][i].fluxo && level[i]==-1){
            level[i] = level[v] + 1;
            q.push(i);
            }
        }
    }
    if(level[201]==-1)
    return false;
    level[201] = INF;
    return true;
}

int DFS(int v, int f){

    if(v == 201)
    return f;
    
    for(int& i=aresta_atual[v];i<202;i++){
        if(M[v][i].capacidade > M[v][i].fluxo && level[v]<level[i]){
        int value = DFS(i,min(f,M[v][i].capacidade - M[v][i].fluxo));
        if(value > 0){
                M[v][i].fluxo += value;
                M[i][v].fluxo -= value;
                return value;
        }
        }
    }

    return 0;

}

void Dinic(){
    while(BFS()){
        fill(aresta_atual.begin(),aresta_atual.end(),0);
        while(int f = DFS(0,INF)){
            result+=f;
        }
    }
    return;
}



int main(){
    while(cin>>n>>m>>k){
    instancia++;
    result = 0;
    fill(M.begin(), M.end(), vector<Aresta>(202));
    vector<int> cavalos;

    
    rep(i,0,n) { int aux; cin>>aux; cavalos.push_back(aux);}
    rep(i,0,k) {int c,s; cin>>c>>s; M[s][c+100].capacidade = 1; /*residual*/ M[c+100][s].capacidade = 1; M[c+100][s].fluxo = 1;}

    repr(i,0,m) {M[0][i].capacidade = 1; /*residual*/ M[i][0].capacidade = 1; M[i][0].fluxo = 1;}
    rep(i,0,cavalos.size()) {M[i+100+1][201].capacidade = cavalos[i]; /*residual*/ M[201][i+100+1].capacidade = cavalos[i];  M[201][i+100+1].fluxo = cavalos[i];}

    Dinic();

    cout<<"Instancia "<<instancia<<endl;
    cout<<result<<endl;
    cout<<endl;
    }
    return 0;
}
