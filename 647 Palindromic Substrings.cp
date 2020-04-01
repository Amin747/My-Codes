class Solution {
public:
    int countSubstrings(string s) {
        
        int count = 0;
        int n = s.length();
        if(n==1) return 1;
        
        vector<vector<int>>matrix;
        
        for (int i = 0; i<s.length(); i++){
            vector<int>temp (s.length(), 0);
            matrix.push_back(temp);
        }
        
        for (int i=0; i<matrix.size(); i++){
            matrix[i][i]=1;
            count++;
        }
        for (int j=1; j<matrix[0].size(); j++){
            for (int i=0; i<matrix.size(); i++){
                if(i+1==j && s[i]==s[j]){
                    matrix[i][j]=1;
                    count++;
                }
                else {
                    if(i+1<n && matrix[i+1][j-1]==1 && s[i]==s[j]){
                        count++;
                        matrix[i][j]=1;
                    }
                }
            }
        }
        return count;
    }
};
