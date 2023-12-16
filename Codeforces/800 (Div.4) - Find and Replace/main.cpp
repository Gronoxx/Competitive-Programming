#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    int t;
    cin>>t;
    for(int test=0;test<t;test++){
        int n;
        vector<int> pos(26,-1);
        cin>>n;
        string s;
        bool p=true;;
        for(int i=0;i<n;i++){
            if(!p){
            cin>>s[i];
            continue;
            }
            cin>>s[i];
            if(i%2==0){
            if(pos[s[i]-97]==1){
            cout<<"NO"<<endl;
            p=false;
            break;
            }
            pos[s[i]-97]=0;
            }
            else{
            if(pos[s[i]-97]==0){
            cout<<"NO"<<endl;
            p=false;
            break;
            }
            pos[s[i]-97]=1;
            }
        }
        if(p)
        cout<<"YES"<<endl;

    }

    return 0;
}