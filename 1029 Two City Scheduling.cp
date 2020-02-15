class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum = 0;
        vector<pair<int,int>>defs;
        pair<int,int>p;
        for (int i =0; i<costs.size(); i++){
            p.first = costs[i][0]-costs[i][1];
            p.second = i;
            defs.push_back(p);
        }
        sort(defs.begin(), defs.end());
        for (int i=0; i< defs.size()/2; i++){
            sum+= costs[defs[i].second][0];
        }
        for (int i=defs.size()/2; i<defs.size() ; i++){
            sum+= costs[defs[i].second][1];
        }
        return sum;
        
    }
};
