#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

struct dupla{
    int id;
    int distancia;
};
struct CompareSecond {
    bool operator()(const dupla& a, const dupla& b) const {
        return a.distancia > b.distancia;
    }
};
struct Point{
    int id;
    int x,y;
};

int dijkstra(vector<vector<dupla>> &adj, int n,vector<Point> &pontos){
    int resultado=0;
    priority_queue<dupla, vector<dupla>, CompareSecond> pq;
    vector<bool> popped (n,false);
    dupla aux;
    aux.id=0;
    aux.distancia=0;
    pq.push(aux);
    while(!pq.empty()){
        dupla atual = pq.top();
        pq.pop();
        if(popped[atual.id]==false){
            popped[atual.id]=true;
            resultado+=atual.distancia;
            for(int i =0; i<adj[atual.id].size();i++){
                pq.push(adj[atual.id][i]);
            }
        }
    }
    return resultado;
}

int main(){

    int testcases;
    cin>>testcases;
    for(int t=0;t<testcases;t++){
        vector<Point> pontos;
        int n;
        cin>>n;
        vector<int> valores(2*n);
        for(int i=0;i<2*n;i++){
            cin>>valores[i];
        }
        std::sort(valores.begin(), valores.end());
        for(int i=0;i<n;i++){
            Point aux;
            aux.y=valores[i];
            aux.x=valores[((2*n)-1)-i];
            aux.id=i;
            pontos.push_back(aux);
        }   
        vector<vector<dupla>> adj(n);
        for (int i =0;i<n;i++){
            Point aux= pontos[i];
            for (int count =0;count<n;count++){
                if(i==count)
                continue;
                int d1=(pontos[i].x-pontos[count].x);
                int d2=(pontos[i].y-pontos[count].y);
                if(d1<0)
                d1=d1*-1;
                if(d2<0)
                d2=d2*-1;
                int d = d1+d2; 
                dupla aux;
                aux.distancia=d;
                aux.id=count;
                adj[i].push_back(aux);
            }
        }
        cout<<dijkstra(adj,n,pontos)<<endl;
        for(int i=0;i<n;i++){
            cout<<pontos[i].x<<" "<<pontos[i].y<<endl;
        }
    }

    return 0;
}