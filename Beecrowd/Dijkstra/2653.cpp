#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
    unordered_map<string, int> Map;
    string line;
    int count=0;
    while(getline(cin,line)){
        if(Map.count(line) > 0){

        }
        else{
            count++;
            Map[line] = count;
        }
    }
    cout<<count<<endl;
    return 0;
}
