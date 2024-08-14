class Solution {
public:
    int lengthOfLastWord(string s) {
    int result=0;
    int backup=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
        if(result!=0)
        backup=result;
        result=0;
        }
        else
        result++;
    }
    if(result!=0)
    return result;
    return backup;    
    }
};
