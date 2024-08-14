class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_map<char,bool> m;
    int maxi=0;
    int start=0;
    for(int i=0;i<s.size();i++){
        if(m[s[i]]==false){
            m[s[i]]=true;
        }
        else{
            maxi = max(i-start,maxi);
            while(s[start]!=s[i]){
                m[s[start]]=false;
                start++;
            }
            start++;
        }
    }
    return max(int(s.size()-1)-start+1,maxi);
    }
};
