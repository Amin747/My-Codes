class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>>ans;
    int i = 0, j = 0;

    while (i < A.size() && j < B.size()) {
      // Let's check if A[i] intersects B[j].
      // lo - the startpoint of the intersection
      // hi - the endpoint of the intersection
      int lo = max(A[i][0], B[j][0]);
      int hi = min(A[i][1], B[j][1]);
      if (lo <= hi){
          vector<int>temp;
          temp.push_back(lo);
          temp.push_back(hi);
          ans.push_back(temp);
      }
      // Remove the interval with the smallest endpoint
      if (A[i][1] < B[j][1])
        i++;
      else
        j++;
    }
    return ans;
    }
};
