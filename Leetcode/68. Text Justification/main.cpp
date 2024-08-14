class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth){
    vector<string> ans={};
    for(int i=0;i<words.size();i++){
        int currBlank = maxWidth;
        string s="";
        int start = i;
        while(int(words[i].size())<=currBlank){
            currBlank = currBlank - words[i].size() -1;
            i++;
            if(i==words.size())
            break;
        }
        i--;
        currBlank++;
        int base,plus;
        if(i == words.size()-1){
            for(int j=start;j<i;j++)
                s+= words[j] + " ";
            s+= words[i];
            for(int j=0;j<currBlank;j++)
                s+= " ";
        }
        else{
            if(i-start >1){
            base = currBlank / (i - start);
            plus = currBlank - (base * (i - start));
            }
            else{
                base= currBlank;
                plus=0;
            }
            for(int j=start;j<i;j++){
                s+= words[j] + " ";
                for(int k=0;k<base;k++){
                    s+=" ";
                    currBlank--;
                }
                if(plus>0){
                currBlank--;
                s+= " ";
                plus--;
                }
            }
            s+= words[i];
            for(int j=0;j<currBlank;j++)
            s+= " ";
        }
        ans.push_back(s);
    }
    return ans;
}
};
