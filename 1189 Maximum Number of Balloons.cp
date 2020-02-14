class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int>m;
        for (int i=0; i<text.length(); i++){
            if (text[i]=='b'){
                m['b']++;
            }
            if (text[i]=='l'){
                m['l']++;
            }
            if (text[i]=='a'){
                m['a']++;
            }
            if (text[i]=='o'){
                m['o']++;
            }
            if (text[i]=='n'){
                m['n']++;
            }
        }
        int count = 0;
        while(m['b']>0 && m['a']>0 && m['l']>1 && m['o']>1 && m['n']>0){
            m['b']--;
            m['a']--;
            m['l']-=2;
            m['o']-=2;
            m['n']--;
            count++;
        }
        return count;
    }
};
