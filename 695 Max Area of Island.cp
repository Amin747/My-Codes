class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    int res=dfs(i,j,grid);
                    ans=max(res,ans);
                }
            }
        }
        return ans;
    }
    int dfs(int i,int j,vector<vector<int>>& g){
        if(i<0 || i>=g.size() || j<0 || j>=g[0].size() || g[i][j]==0) return 0;
        int res=1;
        g[i][j]=0;
        res+= dfs(i+1,j,g);
        res+= dfs(i-1,j,g);
        res+= dfs(i,j+1,g);
        res+= dfs(i,j-1,g);
        return res;
    }
};
