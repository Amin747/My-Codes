class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ans(n, vector<int>(n));
        int t = 1;
        int row1 = 0;
        int row2 = n-1;
        int col1 = 0;
        int col2 = n-1;
        int i=0;
        
        while (row1<=row2 && col1<=col2) {
            for (int i=col1; i<=col2; i++){
                ans[row1][i] = t;
                t++;
            }
            row1++;
                    
            for (int i=row1; i<=row2; i++){
                ans[i][col2] = t;
                t++;
            }
            col2--;
                            
            for (int i=col2; i>=col1; i--){
                ans[row2][i] = t;
                t++;
            }
            row2--;
            for (int i=row2; i>=row1; i--){
                ans[i][col1] = t;
                t++;
            }
            col1++;
        }
        return ans;
    }
};
