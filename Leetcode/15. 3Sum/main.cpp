class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            int previous_i=i-1;
            if(i>0){
            while(nums[i]==nums[previous_i] && i<nums.size()-1)
            i++;
            }
            previous_i=i;
            int j=i+1;
            int k=nums.size()-1;
            int previous_j=INT_MAX,previous_k=INT_MAX;
            bool p=false;
            while(j<k){
                if(p==true){
                while((nums[j]==nums[previous_j] &&j<nums.size()-1) && j!=previous_j)
                j++;
                while((nums[k]==nums[previous_k]&& k>0) && k!=previous_k)
                k--;
                }
                if(j>=k)
                break;
                previous_j=j;
                previous_k=k;
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    ans.push_back(v);
                    j++;
                }
                else if(nums[i]+nums[j]+nums[k]>0)
                k--;
                else
                j++;
                p=true;
            }
        }
        return ans;
    }
};
