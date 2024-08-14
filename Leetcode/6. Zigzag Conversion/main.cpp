class Solution {
public:
    string convert(string s, int numRows){
    if (numRows == 1) return s; 

    vector<string> result (numRows);
    int currRow =0;
    int aux=1;
    for(int i=0;i<s.size();i++){
        result[currRow] += s[i];
        currRow+= aux;
        if(currRow == 0) 
        aux=1;
        else if(currRow == numRows-1)
        aux=-1;
    }
    string r;
    for(int i=0;i<result.size();i++){
        r+=result[i];
    }
    return r;
}
};
