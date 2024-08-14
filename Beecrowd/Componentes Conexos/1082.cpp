#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Vertice{
    vector<int> vizinhos;
    bool visited =false;
};

void Imprimir(vector<char> c){
    sort(c.begin(),c.end());
    for(int i=0;i<c.size();i++){
        cout<<c[i]<<",";
    }

}

int main(){

    int t,v,e;
    cin>>t;
    for(int test=0;test<t;test++){
    cout<<"Case #"<<test+1<<":";
    cin>>v>>e;
    vector<Vertice> vertices (v);
    for(int i=0;i<e;i++){
        char ca,cb;
        int a,b;
        cin>>ca>>cb;
        a=int(ca)-97;
        b=int(cb)-97;
        vertices[a].vizinhos.push_back(b);
        vertices[b].vizinhos.push_back(a);
    }
    queue<int> Q;
    int result=0;
        for(int k=0;k<v;k++){
            if(vertices[k].visited==false){
                cout<<endl;
                Q.push(k);
                result++;
                vector<char> comp;
                while(!Q.empty()){
                int aux = Q.front();
                Q.pop();
                if(vertices[aux].visited==false){
                vertices[aux].visited=true;
                char c = aux+97;
                comp.push_back(c);
                for(int j=0;j<vertices[aux].vizinhos.size();j++){
                    if(vertices[vertices[aux].vizinhos[j]].visited==false){
                        Q.push(vertices[aux].vizinhos[j]);
                    }
                }
                }
                }
                Imprimir(comp);
            }

        }
    cout<<endl<<result<<" connected components"<<endl<<endl;
    }





    return 0;
}
