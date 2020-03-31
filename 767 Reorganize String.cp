class Solution {
public:
    string reorganizeString(string S) {
        vector<int>letters(26);
        for (int i = 0; i < S.length(); i++) {
            letters[S[i] - 'a']++;
        }
        
        int max = 0;
        int max_letter = 0;
        
        for (int i = 0; i < letters.size(); i++) {
            if (letters[i] > max) {
                max = letters[i];
                max_letter = i;
            }
        }
        
        if (max > (S.length() + 1) / 2) {
            return "";
        }
        
        vector<char>res(S.length());
        int idx = 0;
        while (letters[max_letter] > 0) {
            res[idx] = (char) (max_letter + 'a');
            idx += 2;
            letters[max_letter]--;
        }
        for (int i = 0; i < letters.size(); i++) {
            while (letters[i] > 0) {
                if (idx >= res.size()) {
                    idx = 1;
                }
                res[idx] = (char) (i + 'a');
                idx += 2;
                letters[i]--;
            }
        }
        string ans = "";
        for (int i=0; i<res.size(); i++){
            ans+= res[i];
        }
        return ans;
    }
};
