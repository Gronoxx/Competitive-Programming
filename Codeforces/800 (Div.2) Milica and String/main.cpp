#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int main(){
    int test;
    cin>>test;
    for(int t=0;t<test;t++){
    int n,m;
    cin>>n;
    cin>>m;
    string s;
    cin>>s;
    int a=0,b=0;
    for(int i=0;i<n;i++){
        if(s[i]=='A')
        a++;
        else
        b++;
    }
    int dif = m-b;
    if(dif==0){
    cout<<0<<endl;
    }
    else if(dif>0){
        a=0;
        b=0;
        for(int i=0;i<n;i++){
        if(s[i]=='A')
        a++;
        if(a==dif){
        cout<<1<<endl;
        cout<<i+1<<" B"<<endl;
        break;
        }
        }
    }
    else if(dif<0){
        a=0;
        b=0;
       for(int i=0;i<n;i++){
        if(s[i]=='B')
        b++;
        if(b==-dif){
        cout<<1<<endl;
        cout<<i+1<<" A"<<endl;
        break;
        }
        } 
    }
    
    }
 
 
 
    return 0;
}
