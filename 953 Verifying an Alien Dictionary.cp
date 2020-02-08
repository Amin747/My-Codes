class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int>m;
        for (int i=0; i<order.length();i++){
            m[order[i]]=i;
        }
        
        int i=0;
        int count = 0;
    
        while(i<words.size()){
            if (m[words[i][count]] > m[words[i+1][count]]){
                return false;
            }
            else if (m[words[i][count]] == m[words[i+1][count]]){
                while (count <words[i].length() && count <words[i+1].length()){
                    if (m[words[i][count]] > m[words[i+1][count]]){
                        return false;
                    }
                    count++;
                    if (count==words[i+1].length()-1 && count<words[i].length()-1){
                        return false;
                    }
                }
            }
            i++;
            if (i==words.size()-1) return true;
        }
        return true;
    }
};
