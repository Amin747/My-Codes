class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>>m;
        vector<string>sorted;
        vector<vector<string>>ans;
        for (int i=0; i<strs.size(); i++){
           string temp = strs[i];
           sort(temp.begin(), temp.end());
           sorted.push_back(temp);
           m[temp].push_back(strs[i]);
        }
        
        for (int i=0; i<sorted.size(); i++){
            if (m.count(sorted[i])){
            ans.push_back(m[sorted[i]]);
            m.erase(sorted[i]);
            }
        }
        return ans;
    }
};
