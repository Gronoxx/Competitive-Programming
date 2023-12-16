#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    int count_loaf=0,count_onion=0;
    for(int i=0;i<n;i++){
        if(s[i]=='L'){
           count_loaf++;     
        }
        else{
           count_onion++;
        }
    }

    int count_loaf_k=0,count_onion_k=0;
    int loaf_friend = count_loaf,onion_friend=count_onion;
    for(int i=0;i<n-1;i++){
        if(s[i]=='L'){
            count_loaf_k++;
            loaf_friend--;
            if(count_loaf_k!=loaf_friend && count_onion_k!=onion_friend  ){
                cout<<count_loaf_k+count_onion_k<<endl;
                return 0;
            }
        }
        else{
            count_onion_k++;
            onion_friend--;
            if(count_onion_k!=onion_friend && count_loaf_k!=loaf_friend){
                cout<<count_loaf_k+count_onion_k<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}