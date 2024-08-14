class Solution {
public:
    int maxProfit(vector<int>& prices){
    int result=0;
    bool c=false;
    int atual=0;
    for(int i=0;i<prices.size()-1;i++){
        if(c){
        if(prices[i+1]<prices[i]){
            result += prices[i]-atual;
            c=false; 
        }
        }
        else{
            if(prices[i+1]>prices[i]){
                atual=prices[i];
                c=true;
            }
        }
    }
    if(c){
        result += prices[prices.size()-1]-atual;
    }
    return result;

}
};
