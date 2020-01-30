#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (!numRows) return {};
        if (numRows == 1) return {{1}};
        if (numRows == 2) return {{1},{1,1}};
        else {
            vector<vector<int>>ans;
            ans.push_back({1});
            ans.push_back({1,1});
            int count = 3;
            while(count<=numRows){
                int i = 1;
                vector<int>temp(count);
                temp[0] = 1;
                while (i<temp.size()-1){
                    temp[i] = (ans[count-2][i-1]+ans[count-2][i]);
                    i++;
                }
            temp[temp.size()-1] = 1;
            ans.push_back(temp);
            count++;
            }
        return ans;
        }
    }
};





