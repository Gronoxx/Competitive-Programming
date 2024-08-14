class Solution {
public:
        int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 10000);
        dp[dp.size() - 1] = 0;
    
        for (int i = nums.size() - 2; i >= 0; i--) {
            int end = min(i + nums[i] + 1, static_cast<int> (dp.size()));
            auto it = std::min_element(dp.begin() + i, dp.begin() + end);
            dp[i] = *it + 1;
        }
    
    return dp[0];
}
};
