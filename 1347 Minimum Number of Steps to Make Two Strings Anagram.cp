class Solution {
public:
    int minSteps(string s, string t) {
        map<char ,int> ms;
        map<char, int> mt;
        int ans = 0;
        for(int i=0; i<s.length(); i++){
            if (!ms[s[i]]){
                ms[s[i]]=1;
            }
            else
            ms[s[i]]++;
        }
        for(int i=0; i<t.length(); i++){
            if (!mt[t[i]]){
                mt[t[i]]=1;
            }
            else
            mt[t[i]]++;
        }
        for (char a='a'; a<= 'z'; a++){
            if (mt[a] > ms[a]){
                ans+= mt[a]-ms[a];
            }
        }
        return ans;
    }
};
