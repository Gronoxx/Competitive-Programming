class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

    int total_sum=0,curr_total=0,ans=0;
    for(int i=0;i<gas.size();i++){
        int aux= gas[i]-cost[i];
        total_sum+= aux;
        curr_total+= aux;
        if(curr_total<0){// we cant reach the end of the array with this position
            curr_total=0;
            ans = i+1;
        } 
    }
    if(total_sum<0){ //if we dont have enough gas
        return -1;
    }
    return ans;
        
}

};
