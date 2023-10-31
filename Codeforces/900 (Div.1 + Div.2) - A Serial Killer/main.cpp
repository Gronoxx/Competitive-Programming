#include <iostream>
#include <unordered_map>
#include <string>
 
using namespace std;
 
int main(){
    unordered_map <string,nullptr_t> vic;
    string a;
    string b;
    cin>>a;
    cin>>b;
    cout<<a<<" "<<b<<endl;
    vic[a]=nullptr;
    vic[b]=nullptr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        cin>>b;
        vic.erase(a);
        vic[b]=nullptr;
        int count =0;
        for (const auto& pair : vic) {
        if(count==0)
        std::cout<<pair.first<<" "; 
        else{
        std::cout<<pair.first<<endl;
        break;
        }
        count++;
        }
    }
    return 0;
}