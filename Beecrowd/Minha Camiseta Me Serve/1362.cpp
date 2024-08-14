#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
#define repn(i,a,b) for(int i=a;i>=b;--i)
#define repr(i,a,b) for(int i=a;i<=b;++i)
#define INF 0x3f3f3f3f
#define MAX 38

struct Aresta{
    
    int cap,flu;
    
    Aresta(){
        cap=0;
        flu=0;
    }
};

unordered_map<string,int> mp;
vector<vector<Aresta>> G(MAX,vector<Aresta>(MAX));
vector<int> aresta_atual(MAX,0);
vector<int> level(MAX,-1);

int result;

bool BFS(){
    fill(level.begin(),level.end(),-1);
    queue<int> q;
    q.push(0);
    level[0]=0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        rep(i,1,MAX){
            if(G[v][i].cap > G[v][i].flu && level[i] == -1){
                level[i] = level[v] + 1;
                q.push(i);
            }
        }
    }
    if(level[MAX - 1] == -1)
    return false;
    level[MAX - 1] = INF;
    return true;
}

int DFS(int s, int t){
    
    if(s == MAX-1)
    return t;
    
    for(int &i = aresta_atual[s]; i < MAX; i++){
        if(G[s][i].cap > G[s][i].flu && level[i] > level[s]){
            int value = DFS(i, min(t, G[s][i].cap - G[s][i].flu));
            if(value > 0){
                G[s][i].flu += value;
                G[i][s].flu -= value;
                return value;
            }
        }
    }
    return 0;
}

void Dinic(){
    while(BFS()){
        fill(aresta_atual.begin(),aresta_atual.end(),0);
        while(int k = DFS(0,INF)){
            result +=k;
        }
    }
    return ; 
}





void set(int N){

mp["XS"] = 1;
mp["S"] = 2;
mp["M"] = 3;
mp["L"] = 4;
mp["XL"] = 5;
mp["XXL"] = 6;

G[1][37].cap = N/6;
G[2][37].cap = N/6;
G[3][37].cap = N/6;
G[4][37].cap = N/6;
G[5][37].cap = N/6;
G[6][37].cap = N/6;

}

int main(){
    int t;
    cin>>t;
    rep(tt,0,t){
        fill(G.begin(),G.end(),vector<Aresta>(38));
        result = 0;
        
        int N,M;
        
        cin>>N>>M;
        
        set(N);
        
        rep(i,0,M){
            string a,b;
            
            cin>>a>>b;
            
            G[0][i+7].cap = 1;
            
            G[i+7][mp[a]].cap = 1;
            
            G[i+7][mp[b]].cap = 1;
            
            //Residual
            G[i+7][0].cap = 1;
            G[i+7][0].flu = 1;

            G[mp[a]][i+7].cap = 1;
            G[mp[a]][i+7].flu = 1;

            G[mp[b]][i+7].cap = 1;
            G[mp[b]][i+7].flu = 1;
        }
        
        Dinic();
        if(result == M)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }



    return 0;
}
