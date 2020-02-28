class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a = 0;
        int b = 0;
        int ans=0;
        map<char,int>m;
        while (b<s.length()){
            if (!m.count(s[b])){
                m[s[b]]++;
                int size = m.size();
                ans = max(ans, size);
                b++;
            }
            
            else{
                m.erase(s[a]);
                a++;
            }
        }
        return ans;
    }
};
