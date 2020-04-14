class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size()==0 || matrix[0].size()==0) return false;
        int col = matrix[0].size()-1;
        for (int i=0; i<matrix.size(); i++){
            if (target>= matrix[i][0] && target<= matrix[i][col]){
                if (target==matrix[i][0] || target == matrix[i][col]) return true;
                return bs(matrix, i, target);
            }
        }
        return false;
    }
    
    bool bs(vector<vector<int>>matrix, int i, int target){
        int l = 0;
        int r = matrix[i].size()-1;
        while (l<r){
            int middle = (l+r)/2;
            if (matrix[i][l] == target || matrix[i][r]==target || matrix[i][middle]==target) return true;
            else if (target > matrix[i][middle]){
                l = middle+1;
            }
            else if (target < matrix[i][middle]){
                r = middle - 1;
            }
        }
        return false;
    }
};
