class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int,int>>q;
        vector<vector<bool>>visited;
        vector<bool>vec(image[0].size(), false);
        for(int i=0; i<image.size(); i++){
            visited.push_back(vec);
        }
        
        q.push(make_pair(sr, sc));
        int prev = image[sr][sc];
        image[sr][sc]=newColor;
        visited[sr][sc]=true;
        while (!q.empty()){
        int s = q.size();
        for (int i=0; i<s; i++){
            int row = q.front().first;
            int col = q.front().second;
            if(row-1>=0 && image[row-1][col]==prev && !visited[row-1][col]){
                q.push(make_pair(row-1, col));
                visited[row-1][col]=true;
            }
            if(row+1<image.size() && image[row+1][col]==prev && !visited[row+1][col]){
                q.push(make_pair(row+1, col));
                visited[row+1][col]=true;
            }
            if(col-1>=0 && image[row][col-1]==prev && !visited[row][col-1]){
                q.push(make_pair(row, col-1));
                visited[row][col-1]=true;
            }
            if(col+1<image[0].size() && image[row][col+1]==prev && !visited[row][col+1]){
                q.push(make_pair(row, col+1));
                visited[row][col+1]=true;
            }
            image[row][col] = newColor;
            q.pop();
        }
        }
        return image;
    }
};
