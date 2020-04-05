class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        bool has_left = false;
        bool has_up = false;
        int up;
        int left;
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if (i==0 && j==0){
                    continue;
                }
                if (j-1 >= 0) {
                    left = grid[i][j-1];
                    has_left = true;
                }
                if (i-1 >= 0) {
                    up = grid[i-1][j];
                    has_up = true;
                }
                if(has_left && has_up) grid[i][j]=min(left,up)+grid[i][j];
                else if (!has_up) grid[i][j]=left+grid[i][j];
                else if (!has_left) grid[i][j]=up+grid[i][j];
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};
