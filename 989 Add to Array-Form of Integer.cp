class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int carry = 0;
        for (int i=A.size()-1; i>=0; i--){
            int sum = carry + A[i] + K%10;
            K=K/10;
            carry = sum/10;
            A[i] = sum%10;
        }
        while (K!= 0 ) {
            int sum = carry + K%10;
            A.insert(A.begin(), (sum)%10);
            carry = sum/10;
            K = K/10;
        }
        if (carry!=0){
            A.insert(A.begin(), carry);
        }
        return A;
    }
};
