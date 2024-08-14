#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

void Imprimir(vector<int> & Q){
    string a = " nota(s) de R$";
    string b = " moeda(s) de R$";
    cout<<"NOTAS:"<<endl<<Q[11]<<a<<" 100.00"<<endl<<Q[10]<<a<<" 50.00"<<endl<<Q[9]<<a<<" 20.00"<<endl<<Q[8]<<a<<" 10.00"<<endl<<Q[7]<<a<<" 5.00"<<endl<<Q[6]<<a<<" 2.00"<<endl;
    cout<<"MOEDAS:"<<endl<<Q[5]<<b<<" 1.00"<<endl<<Q[4]<<b<<" 0.50"<<endl<<Q[3]<<b<<" 0.25"<<endl<<Q[2]<<b<<" 0.10"<<endl<<Q[1]<<b<<" 0.05"<<endl<<Q[0]<<b<<" 0.01"<<endl;
}

int main(){

    double n;
    cin>>n;
    n=n*100;
    vector<int> valores = {1,5,10,25,50,100,200,500,1000,2000,5000,10000};
    vector<int> qntd (12,0);
        for(int i=11;i>=0;i--){
            int aux = n/valores[i];
            qntd[i] += aux;
            n = n- valores[i]* aux;
        }
    Imprimir(qntd);

    return 0;
}
