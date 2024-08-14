class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rowUp = matrix.size()-1, colUp=matrix[0].size()-1,rowDown =0, colDown=0;
        int count = (rowUp+1)*(colUp+1);
        int i=0,j=-1;
        bool v=false,h=true,vd=true,hr=true;
        while(count>0){
            if(v){ //vertical
                if(vd){ // down
                    i++;
                    ans.push_back(matrix[i][j]);
                    count--;
                    if(i==rowUp){
                        colUp--;
                        vd=false;
                        v=false;
                        h=true;
                    }
                }
                else{
                    i--;
                    ans.push_back(matrix[i][j]);
                    count--;
                    if(i==rowDown){
                        colDown++;
                        vd=true;
                        v=false;
                        h=true;
                    }
                }
            }
            else if(h){
                if(hr){
                    j++;
                    ans.push_back(matrix[i][j]);
                    count--;
                    if(j==colUp){
                        rowDown++;
                        h=false;
                        hr=false;
                        v=true;
                    }
                }
                else{
                    j--;
                    ans.push_back(matrix[i][j]);
                    count--;
                    if(j==colDown){
                        rowUp--;
                        h=false;
                        hr=true;
                        v=true;
                    }
                }
            }
        }
        return ans;
    }
};
