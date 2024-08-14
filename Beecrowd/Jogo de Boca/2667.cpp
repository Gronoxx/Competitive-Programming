#include <iostream>
#include <string>

using namespace std;

int sumOfDigitis(string n){
    int sum=0;
    for(int i=0;i<n.size();i++){
        sum+=int(n[i])-48;
    }
    return sum;
}


int main(){

    string n;
    cin>>n;
    int s= sumOfDigitis(n);
    if(s%3==0)
    cout<<0<<endl;
    else if(s%3==1)
    cout<<1<<endl;
    else
    cout<<2<<endl;

    return 0;
}
