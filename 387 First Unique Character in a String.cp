class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>m;
        for (int i=0; i<s.length(); i++){
            if(!m[s[i]]){
                m[s[i]]=1;
            }
            else{
                m[s[i]]++;
            }
        }
        
        for (int i=0; i<s.size(); i++){
            if (m[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};
