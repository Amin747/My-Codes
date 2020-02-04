class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char>m;
        for (int i=0; i<s.length(); i++){
            m[s[i]]=t[i];
            for(int j = i; j<s.length(); j++){
                if (t[i]==t[j] && s[i]!=s[j]) {
                    return false;
                }
            }
        }
        
        for (int i=0; i<s.length(); i++){
            if (t[i]!=m[s[i]]){
                return false;
            }
        }
        return true;
    }
};
