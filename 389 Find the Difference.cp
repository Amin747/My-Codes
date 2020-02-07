class Solution {
public:
    char findTheDifference(string s, string t) {
        
        map<char,int>m;
        char ans;
        for(int i=0; i<s.length(); i++){
            if(!m[s[i]]){
                m[s[i]]=1;
            }
            else
                m[s[i]]++;
        }
         for(int i=0; i<t.length(); i++){
            m[t[i]]--;
         }
        for(char a='a'; a<='z'; a++){
            if(m[a]<0){
                return a;
            }
        }
        return ans;
    }
};
