class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int size = citations.size(),result=0;
        int higher=0;
        for(int i=0;i<size;i++){
            if(size - i >=citations[i])
            result = citations[i];
            else if(citations[i]>size)
            higher++;
            else
            result = max(size-i,result);
        }
        return max(result,higher);
    }
};
