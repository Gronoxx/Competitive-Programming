#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int t;
    cin>>t;
    for(int test=0;test<t;test++){
        int n,k;
        cin>>n;
        cin>>k;
        vector<int> numbers(n);
        for (int i=0;i<n;i++){
            cin>>numbers[i];
        }
        vector<bool> visited (n,false);
        //no momento de shiftar podemos apenar pegar o ultimo numero e ver quem esta a essa distancia x 
        //da ultima posição e encontramos que estava em ultimo antes, assim que estrapolarmos o tamanho do for dizemos nao, se encontrarmos o input inicial antes, vemos se 
        //o numero de operações até então é um divisor perfeito do número de operações desejado
        long long unsigned int count=0;
        bool no=false;
        for(int i=0;i<k;i++){
            if(numbers[(n-count%n)-1]>n){
                cout<<"No"<<endl;
                no=true;
                break;
            }
            if(count>0){
            if(visited[(n-count%n)-1]){
                break;
            }
            }
            visited[(n-count%n)-1]=true;
            count += numbers[(n-count%n)-1];
        }
        if(no==false)
        cout<<"Yes"<<endl;
        }
    return 0;
}
// conferir se já passei por todos os elementos
