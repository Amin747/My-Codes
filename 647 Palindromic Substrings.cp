class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        for(int center=0; center<=(2*n)-1; center++){
            int left = center/2;
            int right = left + center%2;
            while(left>=0 && right<n && s[left]==s[right]){
                ans++;
                left--;
                right++;
            }
        }
        return ans;
    }
};
