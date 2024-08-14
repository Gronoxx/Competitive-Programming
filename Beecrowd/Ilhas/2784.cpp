#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

struct Ponto
{
    int id;
    int dis=-1;
};

struct ComparePoint {
    bool operator()(const Ponto& p1, const Ponto& p2) {
        return p1.dis > p2.dis;
    }
};

int difDijkstra(int v_inicial, vector<vector<int>> &M){
    priority_queue<Ponto,vector<Ponto>, ComparePoint> pq;
    Ponto raiz;
    vector<int> all_dis;
    vector<bool> visited(M[0].size(),0);
    raiz.dis =0;
    raiz.id=v_inicial;
    pq.push(raiz);
    while(!pq.empty()){
        Ponto p = pq.top();
        pq.pop();
        if(visited[p.id]==false){
            for(int i=0;i<M[p.id].size();i++){
                if(M[p.id][i]!=-1){
                Ponto novo;
                novo.dis = M[p.id][i] + p.dis; //dis atual + dis pra chegar no proximo
                novo.id = i;
                pq.push(novo);
                }
            }
            visited[p.id]=true;
        all_dis.push_back(p.dis);
        }
    }
    sort(all_dis.begin(),all_dis.end());
    return all_dis[all_dis.size()-1] - all_dis[1];
}


int main(){
int n,m;
cin>>n>>m;
vector<vector<int>> M (n,vector<int>(n,-1));
for(int i=0;i<m;i++){
    int u,v,p;
    cin>>u>>v>>p;
    M[u-1][v-1]=p;
    M[v-1][u-1]=p;    
}
int v;
cin>>v;
v--;
cout<<difDijkstra(v,M)<<endl;

return 0;
}
