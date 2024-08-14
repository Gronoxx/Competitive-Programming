#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
 
std::unordered_map<int, std::unordered_map<int, long long unsigned int>> mapa; //tamanho,soma, quantidade 
 
int sum(string s){
    int ret=0;
    for(int i=0;i<s.size();i++){
        ret+=s[i]-'0';
    }
    return ret;
}
 
long long unsigned int solve(string s){
//direita
    long long unsigned int total=0;
    int size = s.size();
    int soma=sum(s);
    for(int i=2;i<size;i=i+2){
        int aux=0;
        for(int count=0;count<i/2;count++){
            aux+=s[size-count-1] - '0';
        }
        aux=soma-2*aux;
        total+= mapa[size-i][aux];
    }
//esquerda
    for(int i=2;i<size;i=i+2){
        int aux=0;
        for(int count=0;count<i/2;count++){
            aux+=s[count] - '0';
        }
        aux=soma-2*aux;
        total+= mapa[size-i][aux];
    }
//bilateral
    total+= mapa[size][soma];
 
return total;
}
 
int main(){
    int n;
    cin>>n;
    string aux;
    vector<string> tickets(n);
    for(int i=0;i<n;i++){
        cin>>aux;
        mapa[aux.size()][sum(aux)]++;
        tickets[i]=aux;
    }
    long long unsigned int resultado=0;
    for(int i=0;i<n;i++){
        resultado+=solve(tickets[i]);
    }
    cout<<resultado;
 
    return 0;
}
