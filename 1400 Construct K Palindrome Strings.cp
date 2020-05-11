class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length()<k) return false;
        vector<int>alpha(26,0);
        for(int i=0; i<s.length(); i++){
            alpha[s[i]-'a']++;
        }
        int odds = 0;
        for(int i=0; i<26; i++){
            if(alpha[i]%2==1) odds++;
        }
        if(odds>k) return false;
        return true;
    }
};
