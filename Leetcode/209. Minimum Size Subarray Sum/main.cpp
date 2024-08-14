class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size()==0)
        return 0;
        if(nums.size()==1){
            if(target<=nums[0])
            return 1;
            else return 0;
        }
        int i=0,j=0;
        int result=nums[0];
        int ans=0;
        while(j<nums.size()){
            if(result<target){
                j++;
                if(j==nums.size())
                break;
                result+= nums[j];
            }
            else{
                if(ans==0)
                ans=j-i+1;
                else
                ans= min(ans,j-i+1);
                result-=nums[i];
                i++;
            }
        }
        return ans;
    }
};
