#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    
    int n;
    while(cin>>n){
    if(n==0)
    return 0;
    string s;
    cin.ignore(); // Ignora o caractere de nova linha deixado pelo cin
    getline(cin, s); // Lê a linha inteira
    unordered_map<char,int> m;
    int maior_tamanho=0;
    int pointer=0;
    for(int i=0;i<s.size();++i){
        m[s[i]]++;
        while(m.size()>n){ //se ao colocar o elemento estouramos o limite
        //retiramos quantos elementos forem precisos para voltar para o limite
        //utilizamos do ponteiro para deslizar a janela
        m[s[pointer]]--;
        if(m[s[pointer]]==0){ //se com a última retirada conseguimos acabar com um caractere indica q volltamos a n
            m.erase(s[pointer]);
        }
        pointer++;//andamos com o ponteiro para reaizar o deslizamento
        }
        maior_tamanho = max(maior_tamanho,i-pointer+1);
    }   
    cout<<maior_tamanho<<endl;
    }
    return 0;
}
