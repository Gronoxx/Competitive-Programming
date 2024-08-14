#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int resolve(string &a, string &b,vector<vector<int>> &dp, int i, int j){
    if(i==a.size() ||j==b.size())
    return 0;
    if(dp[i][j] !=-1)
    return dp[i][j];
    if(a[i]==b[j])
    dp[i][j]= 1 + resolve(a,b,dp,i+1,j+1);
    else
    dp[i][j] = max(resolve(a,b,dp,i+1,j), resolve(a,b,dp,i,j+1));
    return dp[i][j];
}
int main(){
    string a,b;
    cin>>a>>b;
    int size_a=a.size(), size_b=b.size();
    vector<vector<int>> dp (size_a+1 ,vector<int> (size_b+1,-1));
    cout<<resolve(a,b,dp,0,0)<<endl;
}
