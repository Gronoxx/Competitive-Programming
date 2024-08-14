class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9,vector<bool> (9,false)),col(9,vector<bool> (9,false)), subgrid(9,vector<bool> (9,false));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c = board[i][j];
                if(c == '.')
                continue;
                else{
                    int num = c - '1'; // Convert '1'-'9' to 0-8
                    int sub = (i/3)*3 + (j/3);
                    if(row[i][num]== true || col[j][num]==true || subgrid[sub][num]==true)
                    return false;
                    else{
                        row[i][num]= true; 
                        col[j][num]=true; 
                        subgrid[sub][num]=true;
                    }
                }
            }
        }
        return true;  
    }
};
