class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    int i=0,j=numbers.size()-1;
    vector<int> ans;
    while(i<j){
        if(numbers[i]+numbers[j]<target)
        i++;
        else if(numbers[i]+numbers[j]>target)
        j--;
        else{
            ans.push_back(i+1);
            ans.push_back(j+1);
            return ans;
        }
    }
    return ans;         

}
};
