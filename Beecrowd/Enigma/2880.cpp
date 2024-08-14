#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compareStrings(string a, string b){
    bool result=true;
    for(int i=0;i<a.size();i++){
        if(a[i]==b[i])
        result=false;
    }
    return result;
}

int main(){
string crib,msg;
cin>>crib>>msg;
int result=0;
for(int i=0;i<=crib.size()-msg.size();i++){
    string sub = crib.substr(i,msg.size());
    if(compareStrings(sub,msg))
    result++;
}

cout<<result<<endl;

return 0;
}
