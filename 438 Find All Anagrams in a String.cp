class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        vector<int>svec(26,0);
        vector<int>pvec(26,0);
        if(s.size() < p.size()) return ans;
        
        for (int i=0; i<p.size(); i++){
            svec[s[i]-'a']++;
            pvec[p[i]-'a']++;
        }
        if (svec==pvec) ans.push_back(0);
        
        for(int i=p.size(); i<s.size(); i++){
            svec[s[i]-'a']++;
            svec[s[i-p.size()]-'a']--;
            if (svec==pvec) ans.push_back(i-p.size()+1);
        }
        return ans;
    }
};
