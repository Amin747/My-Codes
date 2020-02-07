class Solution {
public:
    bool isSubsequence(string s, string t) {
        int t_index = 0;
        int s_index = 0;
        if (s.length()==0)return true;
        if (t.length()==0)return false;
        while(t_index<t.size()){
            if (t[t_index]==s[s_index]){
                s_index++;
                if (s_index==s.size()){
                    return true;
                }
            }
            t_index++;
        }
        return false;
    }
};
