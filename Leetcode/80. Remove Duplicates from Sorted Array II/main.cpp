class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=0,aux=-101;
        bool second=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=aux){
                aux= nums[i];
                nums[index] = aux;
                index++;
                second =false;
            }
            else{
                if(!second){
                    nums[index] = aux;
                    index++;
                    second=true;
                }
            }
        }
        return index;
    }
};
