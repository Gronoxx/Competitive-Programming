class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n>0){
        int count2=0;
        queue <int> q;
        for(int i=0;i<nums1.size();i++){
            //fila vazia
            if(q.empty()){
    
            if(i>=m){
            // ja passamos por todos de nums1
            nums1[i] = nums2[count2];
            count2++;
            }
            else if(nums1[i]<nums2[count2]){}
            else{
                q.push(nums1[i]);
                nums1[i] = nums2[count2];
                count2++;
            }
            
            }
            else{
                if(i>=m && count2>=n){
                    //so a fila eh valida
                    nums1[i]=q.front();
                    q.pop();
                }
                else if(i>=m && count2<n){
                    //fila e count2 valida
                    if(q.front()<nums2[count2]){
                        nums1[i]=q.front();
                        q.pop();
                    }
                    else{
                        nums1[i] = nums2[count2];
                        count2++;
                    }
                }
                else if(i<m && count2>=n){
                    //fila e nums1 valido
                    if(q.front()<nums1[i]){
                        q.push(nums1[i]);
                        nums1[i]=q.front();
                        q.pop();
                    }
                    else{
                    }
                }
                //todos validos
                else if(q.front()<=nums1[i] && q.front() <= nums2[count2]){
                    q.push(nums1[i]);
                    nums1[i]=q.front();
                    q.pop();
                }
                else if(nums1[i]<=q.front() &&  nums1[i] <= nums2[count2]){
                    
                }
                else{
                    q.push(nums1[i]);
                    nums1[i] = nums2[count2];
                    count2++;
                }
            }
        }
    
        }        
    }

};
