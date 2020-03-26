class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int counter = 0;
        if (matrix.size()==0 || matrix[0].size()==0) return ans;
        for (int j = 0; j<matrix[0].size(); j++){
            int i=0;
            vector<int>temp;
            int j1 = j;
            while (i<matrix.size() && j1>=0){
                temp.push_back(matrix[i][j1]);
                i++;
                j1--;
            }
            counter++;
            if (counter%2==1){
                reverse(temp.begin(), temp.end());
            }
            for (int k=0; k<temp.size(); k++){
                ans.push_back(temp[k]);
            }
        }
        
        for (int i=1; i<matrix.size(); i++){
            int j=matrix[0].size()-1;
            vector<int>temp;
            int i1 = i;
            while(i1<matrix.size() && j>=0){
                temp.push_back(matrix[i1][j]);
                i1++;
                j--;
            }
            counter++;
            if (counter%2==1){
                reverse(temp.begin(), temp.end());
            }
            for (int k=0; k<temp.size(); k++){
                ans.push_back(temp[k]);
            }
        }
        return ans;
    }
};
