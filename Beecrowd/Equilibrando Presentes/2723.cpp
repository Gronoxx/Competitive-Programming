#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool solver (vector<int>& presentes, int atual, int A, int B, int n){
    if(abs(A-B) > 5)
        return false;
    else if(atual == n)
        return true;
    else {
        return (solver (presentes,atual+1, A + presentes[atual] , B, n) || solver (presentes,atual+1, A , B + presentes[atual], n));
    }
}


int main(){
    
    int t;
    cin>>t;
    for(int count=0; count< t ; count++){
        int n;
        cin>>n;
        vector<int> presentes;
        for(int i=0 ; i < n ; i++){
            int aux;
            cin>>aux;
            presentes.push_back(aux);
        }
        if(solver(presentes,0,0,0,n))
        cout<<"Feliz Natal!"<<endl;
        else
        cout<<"Ho Ho Ho!"<<endl;   
    }



    return 0;
}
