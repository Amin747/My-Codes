class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int>ms;
        if (s.length()!=t.length())return false;
        for (int i=0; i<s.length(); i++){
            if (!ms[s[i]]) {
                ms[s[i]] = 1;
            }
            else {
                ms[s[i]]++;
            }
        }
        for (int i=0; i<t.length(); i++){
            if (!ms[t[i]]) return false;
            else{
                ms[t[i]]--;
                if (ms[t[i]]<0){
                    return false;
                }
            }
        }
        return true;
    }
};
