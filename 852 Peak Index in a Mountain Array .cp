class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int maxim = INT_MIN;
        int ans=0;
        for (int i=0; i<A.size(); i++){
            if(A[i]>maxim){
                maxim = A[i];
                ans = i;
            }
        }
        return ans;
    }
};
