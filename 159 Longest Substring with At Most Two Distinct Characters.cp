class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.length()==0) return 0;
        int ans = 0;
        int a = 0;
        int b = 0;
        map<char,int>m;
        int temp=0;
        while (b<s.length()){
            if (m.count(s[b]) || m.size()<2){
                m[s[b]]++;
                b++;
                temp++;
                ans = max(temp, ans);
            }
            else {
                if (m[s[a]]==1){
                    m.erase(s[a]);
                    temp--;
                }
                else {
                    m[s[a]]--;
                    temp--;
                }
                a++;
            }
        }
        return ans;
    }
};
