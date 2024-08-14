class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    int cam = int(matrix[0].size())/2, total=matrix.size()*matrix.size();
    if(int(matrix[0].size())%2==1)
    total--;

    for(int i=0;i<cam;i++){
        int counter = 0;
        while(counter<(matrix.size() - 2*i)-1){
        int maxi = matrix.size() - i;
        int mini = i;
        int j=i,k=i+1;
        int holder = matrix[j][k-1];
        
        while(k<maxi){    
                int aux = matrix[j][k];
                matrix[j][k] = holder;
                holder =aux;
                k++;
            }
        k--;
        while(j<maxi-1){
                j++;
                int aux = matrix[j][k];
                matrix[j][k] = holder;
                holder = aux;
        }
        k--;
        while(k>=i){    
                int aux = matrix[j][k];
                matrix[j][k] = holder;
                holder = aux;
                k--;
        }
        k++;
        j--;
        while(j>=i){
            int aux = matrix[j][k];
            matrix[j][k] = holder;
            holder = aux;
            j--;
        }
        counter++;
        }     
    }
    }

};
