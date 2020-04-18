class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st;
        for (string word: wordList){
            st.insert(word);
        }
        if (!st.count(endWord)) return 0;
        
        int level = 1;
        
        queue<string>q;
        q.push(beginWord);
        while (!q.empty()){
            int s = q.size();
            for (int i=0; i<s; i++){
                string word = q.front();
                q.pop();
                for (int j=0; j<word.length(); j++){
                    char original_char = word[j];
                    for (char c = 'a'; c<= 'z'; c++){
                        if (word[j]==c) continue;
                        word[j] = c;
                        if (word == endWord) return level+1;
                        if (st.count(word)){
                            q.push(word);
                            st.erase(word);
                        }
                    }
                    word[j] = original_char;
                }
            }
            level++;
        }
        return 0;
    }
};
