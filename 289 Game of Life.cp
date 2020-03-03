class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>ans;
        int rows = board.size()-1;
        int cols = board[0].size()-1;
        
        map<pair<int,int>, int>m;
        
        for (int i=0; i<=rows; i++){
            for (int j=0; j<=cols; j++){
                m[make_pair(i,j)] = board[i][j];
            }
        }
        for (int i=0; i<=rows; i++){
            for (int j=0; j<=cols; j++){
                if (m[make_pair(i,j)]==1 && ones(i, j, rows, cols, m) == 0 || ones (i, j, rows, cols, m) == 1) board[i][j] = 0;
                if (m[make_pair(i,j)]==1 && ones(i, j, rows, cols, m) == 2 || ones (i, j, rows, cols, m) == 3) board[i][j] = 1;
                if (m[make_pair(i,j)]==1 && ones(i, j, rows, cols, m) > 3) board[i][j] = 0;
                if (m[make_pair(i,j)]==1 && ones(i, j, rows, cols, m) == 3) board[i][j] = 1;
            }
        }
        
    }
    int ones(int i, int j, int rows, int cols, map<pair<int,int>, int>m){
            int ans = 0;
            if (j>=1) ans += m[make_pair(i,j-1)];
            if (j<cols) ans += m[make_pair(i,j+1)];
            if (i>=1) ans += m[make_pair(i-1, j)];
            if (i<rows) ans += m[make_pair(i+1, j)];
            if (j>=1 && i>=1) ans += m[make_pair(i-1, j-1)];
            if (i<rows, j<cols) ans += m[make_pair(i+1, j+1)];
            if (i>=1 && j<cols) ans += m[make_pair(i-1, j+1)];
            if (j>=1 && i<rows) ans += m[make_pair(i+1, j-1)];
            return ans;
        }
};
