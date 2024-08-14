#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool isRowIdentical(const std::vector<bool>& row, const std::vector<bool>& vec) {
    return row == vec;
}

int findIdenticalRow(const std::vector<std::vector<bool>>& matrix, const std::vector<bool>& vec) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        if (isRowIdentical(matrix[i], vec)) {
            return i; 
        }
    }
    return -1;
}


void ChangeVector(vector<bool> &compare, vector<bool> &change){

    for(int i=0;i<compare.size();i++){
        if(compare[i]!=change[i])
        change[i]=1;
        else
        change[i]=0;
    }

}


int main(){

int n,m,l;
cin>>n;
cin>>m>>l;

vector<bool> s_inicial(m,false);
for(int i=0;i<l;i++){
    int aux;
    cin>>aux;
    s_inicial[aux-1]=true;    
}
vector<vector<bool>> M (n,vector<bool>(m,0)); //1= impar, 0=par
for(int i=0;i<n;i++){
    int count=0;
    cin>>count;
    if(i!=0){
        for(int j=0;j<m;j++){
        M[i][j]=M[i-1][j];
        }
    }
    for(int k=0;k<count;k++){
        int aux;
        cin>>aux;
        M[i][aux-1]=!M[i][aux-1];
    }
}

int aux = findIdenticalRow(M,s_inicial);
if(aux==-1){
ChangeVector(M[n-1],s_inicial);
int aux = findIdenticalRow(M,s_inicial);
if(aux==-1)
cout<<aux<<endl;
else{
    cout<<n+aux+1<<endl;
}
}
else{
    cout<<aux+1<<endl;
}

return 0;
}
