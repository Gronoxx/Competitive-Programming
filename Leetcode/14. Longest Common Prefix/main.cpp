class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for(int i=1;i<strs.size();i++){
            string s = "";
            int ceil = min(prefix.size(),strs[i].size());
            for(int j=0;j<ceil;j++){
                if(prefix[j]==strs[i][j])
                s+=prefix[j];
                else
                break;
            }
            prefix=s;
        }    
        return prefix;
    }
};
