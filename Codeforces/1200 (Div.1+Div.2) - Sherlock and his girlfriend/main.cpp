#include <iostream>
#include <unordered_map>
#include <cmath>
 
using namespace std;
 
int main(){
    int n;
    cin>>n;
    n++;
    int cores = log2(n);
    cout<<cores<<endl;
    int total_count=0;
    for(int i=1;i<=cores;i++){
        for (int count=0;count<pow(2,i);count++){
            if(total_count==n-2){
                cout<<i;
                break;
            }
            cout<<i<<" ";
            total_count++;
        }
    }
    return 0;
}