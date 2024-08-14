class Solution {
public:
    int strStr(string haystack, string needle) {
    int count = 0;
    int ans =-1;
        for(int i=0;i<haystack.size();i++){
            if(haystack[i]==needle[count])
            ans=i;
            while(haystack[i]==needle[count]){
                i++;
                count++;
                if(count==needle.size())
                return ans;
                if(haystack[i]!=needle[count]){
                    i=ans;
                    count = 0;
                    ans = -1;
                    break;
                }
            }
        }
        return ans;
    }
};
