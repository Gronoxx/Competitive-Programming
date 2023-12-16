#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <chrono>

using namespace std;

struct Node{
    int id;
    int value;
    int pe;
    int pd;
    int lvl;
};

bool BinarySearch(int l, int r, int x, vector<int> & powers){
    if(r>=l){
    int m = l + (r - l) / 2;
    if(powers[m]==x)
    return true;
    if(powers[m]>x)
    return BinarySearch(l,m-1,x,powers);
    else
    return BinarySearch(m+1,r,x,powers);
    }
    return false;
}

bool isPower(int x, int y){
    int pow = x, i = 1;
    while(pow<y){
        pow=pow*pow;
        i*=2;
    }
    if(pow==y)
    return true;
    else{
        vector<int> powers;
        for (int count = (i / 2)+1; count < i; count++) {
            int result = static_cast<int>(std::pow(x, count));
            powers.push_back(result);
        }
        return BinarySearch(0,powers.size()-1,y,powers);
    }
}

void Tree_Gen(unordered_map<int,Node> &numbers,Node node,int n){
    if(node.pd==n-1){ //não tem si o que somar
        return;
    }
    Node aux;
    aux.id = node.id+(n-node.lvl);
    aux.lvl=node.lvl+1;
    aux.pd=node.pd+1;
    aux.pe=node.id;
    aux.value=numbers[aux.pd].value + numbers[aux.pe].value;
    numbers[aux.id] = aux;
    Tree_Gen(numbers,aux,n);
    return;
}

int main(){
int n,k;
cin>>n;
cin>>k;
unordered_map<int,Node> numbers;
for (int i=0; i <n;i++)
{
    int value;
    cin>>value;
    Node aux;
    aux.id=i;
    aux.value=value;
    aux.pe=i;
    aux.pd=i;
    aux.lvl=0;
    numbers[i]=aux;
}
for (int i=0;i<n;i++){
    Tree_Gen(numbers,numbers[i],n);
}
int count=0;
for (const auto& pair : numbers) {
        if(isPower(k,pair.second.value))
        count++;
        else
        continue;
    }
    cout<<count<<endl;

return 0;
}