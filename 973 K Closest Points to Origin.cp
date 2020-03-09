class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<int,int>>distances;
        vector<vector<int>>ans;
        
        for (int i=0; i<points.size(); i++){
            int sum = pow(points[i][0], 2)+ pow(points[i][1], 2);
            distances.push_back(make_pair(sum, i));
        }
        
        sort(distances.begin(), distances.end());
        
        for (int i = 0; i<K; i++){
            ans.push_back(points[distances[i].second]);
        }
        return ans;
    }
};
