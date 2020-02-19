class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.size()==0) return;
        int rows = rooms.size()-1;
        int cols = rooms[0].size()-1;
        queue<pair<int,int>>q;
        
        for (int i=0; i<=rows; i++){
            for (int j=0; j<=cols; j++){
                if (rooms[i][j]==0){
                    pair<int,int>p = {i,j};
                    q.push(p);
                }
            }
        }
        pair<int,int>p;
        int counter = 1;
        while (!q.empty()){
            int size = q.size();
            for (int i=0; i< size; i++){
                if (q.front().second-1 >= 0 && rooms[q.front().first][q.front().second-1]==2147483647){
                    rooms[q.front().first][q.front().second-1] = counter;
                    p = {q.front().first, q.front().second-1};
                    q.push(p);
                }
                if (q.front().second+1 <= cols && rooms[q.front().first][q.front().second+1]==2147483647){
                    rooms[q.front().first] [q.front().second+1] = counter;
                    p = {q.front().first, q.front().second+1};
                    q.push(p);
                }
                if (q.front().first-1 >=0 && rooms[q.front().first-1][q.front().second]==2147483647){
                    rooms[q.front().first-1] [q.front().second] = counter;
                    p = {q.front().first-1, q.front().second};
                    q.push(p);
                }
                if (q.front().first+1 <= rows && rooms[q.front().first+1][q.front().second]==2147483647){
                    rooms[q.front().first+1] [q.front().second] = counter;
                    p = {q.front().first+1, q.front().second};
                    q.push(p);
                }
                q.pop();
            }
            counter++;
        }
    }
};
