#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;

int main(){
unordered_map<int,int> values;
int n;
int k;
cin>>n;
cin>>k;
vector<int> numbers(n);
for (int i=0; i<n;i++)
{
    cin>>numbers[i];
}
for(int count=0;count<n;count++){
    int sum=numbers[count];
    values[sum]++;
    for (int i=1;count+i<n;i++){
        sum+=numbers[count+i];
        values[sum]++;
    }
}
int total=0;
long long signed const_k=k;
while(const_k<1000000000){
    total+=values[const_k];
    const_k=const_k*k;
}
cout<<total<<endl;

return 0;
}