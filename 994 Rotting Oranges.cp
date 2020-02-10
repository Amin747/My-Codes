class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int col = grid[0].size()-1;
        int row = grid.size()-1;
        queue<pair<int,int>>q;
        
        for (int i=0; i<=row; i++){
            for (int j=0; j<=col; j++){
                if (grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int mins=0;
        while(!q.empty()){
            int size = q.size();
            for (int i=0; i<size; i++){
                if (q.front().first-1 >= 0 && grid[q.front().first-1][q.front().second] == 1){
                    grid[q.front().first-1][q.front().second] =2;
                    pair<int,int>p1 = {q.front().first-1, q.front().second};
                    q.push(p1);
                }
                if (q.front().first+1 <= row && grid[q.front().first+1][q.front().second] == 1){
                    grid[q.front().first+1][q.front().second] =2;
                    pair<int,int> p2 = {q.front().first+1, q.front().second};
                    q.push(p2);
                }
                if (q.front().second+1 <= col && grid[q.front().first][q.front().second+1] == 1){
                    grid[q.front().first][q.front().second+1] = 2;
                    pair<int,int> p3 = {q.front().first,q.front().second+1};
                    q.push(p3);
                }
                if (q.front().second-1 >= 0 && grid[q.front().first][q.front().second-1] == 1){
                    grid[q.front().first][q.front().second-1] =2;
                    pair<int,int>p4 ={q.front().first,q.front().second-1};
                    q.push(p4);
                }
                q.pop();
            }
            mins++;
        }
        for (int i=0; i<=row; i++){
            for (int j=0; j<=col; j++){
                if (grid[i][j]==1){
                    return -1;
                }
            }
        }
        if (mins==0) return 0;
        return mins-1;
    }
};
