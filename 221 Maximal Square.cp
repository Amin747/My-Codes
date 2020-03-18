class Solution {
public:
    vector<int>finds;
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size()==0) return 0;
        for (int i=0; i<matrix.size(); i++){
            for (int j=0; j<matrix[0].size(); j++){
                if (matrix[i][j]=='1'){
                    finds.push_back(1);
                    int count = 1;
                    bool flag = true;
                    while(i+count<matrix.size() && j+count<matrix[0].size() && flag){
                        for (int k=j; k<=j+count; k++){
                            if (matrix[i+count][k]!='1'){
                                flag = false;
                                break;
                            }
                        }
                        for (int l=i; l<i+count; l++){
                            if (matrix[l][j+count]!='1'){
                                flag = false;
                                break;
                            }
                        }
                        if (flag)
                            count++;
                    }
                    finds.push_back(count);
                }
            }
        }
        if (finds.empty()) return 0;
        make_heap(finds.begin(), finds.end());
        return finds.front()*finds.front();
    }
};
