#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        if (rowIndex == 1) return {1,1};
        int count = 2;
            vector<vector<int>> last;
            last.push_back({1});
            last.push_back({1,1});
            while (count <= rowIndex){
                vector<int>temp(count+1);
                int i = 1;
                temp[0]=1;
                while(i<count){
                    temp[i] = last[count-1][i-1]+last[count-1][i];
                    i++;
                }
                temp[temp.size()-1]=1;
                last.push_back(temp);
                count++;
            }
        return last[rowIndex];
    }
};
