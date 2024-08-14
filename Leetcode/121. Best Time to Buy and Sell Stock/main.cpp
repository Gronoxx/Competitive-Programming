class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int min_atual=prices[0];
    int max_atual=0;
    for(int i=1;i<prices.size();i++){
        if(prices[i]-min_atual>max_atual){
            max_atual = prices[i]-min_atual;
        }
        else if(prices[i]<min_atual){
            min_atual=prices[i];
        }
    }
    return max_atual;
    }
};
