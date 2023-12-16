#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int test=0;test<t;test++){
    int n;
    int m;
    cin>>n;
    cin>>m;
    if(m==1)
    cout<<0<<endl;
    else if(n>=m)
    cout<<m<<endl;
    else{
        cout<<n+1<<endl;
    }
    for(int count=0; count<n;count++){
        for(int i=count+1;i<m+count+1;i++){
            if(i%m==count+1){
                m++;
                i++;
            }
                cout<<i%m<<" ";
        }
        cout<<endl;
    }
    }
   return 0;
}