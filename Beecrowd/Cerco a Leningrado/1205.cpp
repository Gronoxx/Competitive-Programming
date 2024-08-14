#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

struct Ponto{
    int id,dis;
};
struct ComparePoint {
    bool operator()(const Ponto& p1, const Ponto& p2) {
        return p1.dis > p2.dis;
    }
};

int Dijkstra(int v_inicial,int v_final,vector<vector<int>> &M){
    priority_queue<Ponto,vector<Ponto>, ComparePoint> pq;
    vector<bool> visited(M[0].size(),0);
    Ponto ponto;
    ponto.id=v_inicial;
    ponto.dis= M[v_inicial][v_inicial];
    pq.push(ponto);
    while(!pq.empty()){
        Ponto p = pq.top();
        if(p.id==v_final)
        return p.dis;
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
        }
    }
    return -1;
}

int main(){
    int n,m,k;
    double p;
    while(cin>>n){
        cin>>m>>k>>p;
        vector<vector<int>> g (n);
        vector<int> soldados(n,0);
        for(int i=0;i<n;i++){
            g[i].push_back(i);
        }
        for(int i=0;i<m;i++){
            int aux,aux2;
            cin>>aux;
            cin>>aux2;
            g[aux-1].push_back(aux2-1);
            g[aux2-1].push_back(aux-1);
        }
        int A;
        cin>>A;
        for(int i=0;i<A;i++){
            int aux;
            cin>>aux;
            soldados[aux-1]++;
        }
        int partida,destino;
        cin>>partida>>destino;
        vector<vector<int>> M(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int count=0;count < g[i].size();count++){
                if(M[i][g[i][count]]==-1)
                M[i][g[i][count]] = soldados[g[i][count]];
                else
                M[i][g[i][count]] = min (M[i][g[i][count]],soldados[g[i][count]]);
            }
        }
        int qntd_soldados = Dijkstra(partida-1,destino-1,M);
        if(qntd_soldados > k)
        cout<<"0.000"<<endl;
        else{
        long double r = pow(p,qntd_soldados);
        if(qntd_soldados==-1)
        r=0.000;
        cout << fixed << setprecision(3) << r << endl;      
        }
    }



    return 0;
}
