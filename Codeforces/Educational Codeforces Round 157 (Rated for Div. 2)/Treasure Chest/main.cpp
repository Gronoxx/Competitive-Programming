#include <iostream>
#include <vector>

using namespace std;
int main(){
    int testcases;
    cin>>testcases;
    for (int t=0;t<testcases;t++){
        int c,k,t3;
        cin>>c;
        cin>>k;
        cin>>t3;
        if(c>k)
        cout<<c<<endl;
        else if(c<k){
        if(c+t3>k)
        cout<<k<<endl;
        else
        cout<<(k+(k-(c+t3)))<<endl;
        }
        else
        cout<<c;
    }
    return 0;
}