class Solution {
public:
    bool canJump(vector<int>& nums) {
        int closer = nums.size()-1;
    for(int i=nums.size()-2;i>=0;i--){
        if(closer - i <= nums[i])
        closer = i;
    }
    if(closer==0)
    return true;
    return false;
    }
};
