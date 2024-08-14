#include <iostream>
    #include <algorithm>
    #include <stack>
    #include <queue>

    using namespace std;

    int main(){
        int n;
        while(cin>>n){
            bool s=true,pq=true,q=true,imp=false;
            stack<int> pilha;
            queue<int> fila;
            priority_queue<int> fila_p;
            for(int i=0;i<n;i++){
            int command,number;
            cin>>command>>number;
            if(command==1){
                pilha.push(number);
                fila.push(number);
                fila_p.push(number);
            }
            else{
                int aux_s,aux_pq,aux_q;
                aux_s=pilha.top();
                pilha.pop();
                aux_q = fila.front();
                fila.pop();
                aux_pq=fila_p.top();
                fila_p.pop();
                if(aux_s!=number)
                s=false;
                if(aux_pq!=number)
                pq=false;
                if(aux_q!=number)
                q=false;
                }
            }
            if(s && !pq && !q)
            cout<<"stack"<<endl;
            else if(!s && pq && !q)
            cout<<"priority queue"<<endl;
            else if(!s && !pq && q)
            cout<<"queue"<<endl;
            else if (!s && !pq && !q)
            cout<<"impossible"<<endl;
            else
            cout<<"not sure"<<endl;
        }


        return 0;
    }
