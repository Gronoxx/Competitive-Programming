class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    int aux = nums[0];
    long long index=0;
    vector<bool> visited (nums.size());
    int size =nums.size();
    for(int i=0;i<nums.size();i++){
        if(visited[(index+k)%nums.size()]==true){
            index++;
            aux=nums[index%nums.size()];
        }
        int aux2= nums[(index+k)%nums.size()];
        nums[(index+k)%nums.size()]= aux;
        visited[(index+k)%nums.size()]=true;
        aux= aux2;
        index = index + k;
    }    
    
    }
};
