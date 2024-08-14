class Solution {
public:
    int trap(vector<int>& height) {
    // min(max (left), max(right)) - altura atual
    vector<int> left(height.size());
    vector<int> right(height.size());
    left[0] = height[0];
    right[right.size()-1] = height[height.size()-1];
    for(int i=1;i<height.size();i++){
        left[i] = max(height[i],left[i-1]);
    }
    for(int i=height.size()-2;i>=0;i--){
        right[i] = max(height[i],right[i+1]);
    }
    int result=0;
    for(int i=0;i<height.size();i++){
        result+= min(left[i],right[i]) - height[i];
    }
    return result;

}
};
