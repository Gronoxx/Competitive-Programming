class Solution {
public:
    int maxArea(vector<int>& height) {
    int i=0,j=height.size()-1;
    int result=0;
    while(i<j){
        if(height[i] < height[j]){
            result= max(result, (height[i]* (j-i)));
            i++;
        }
        else{
            result= max(result, (height[j]* (j-i)));
            j--;
        }
    }
    return result;
}
};
