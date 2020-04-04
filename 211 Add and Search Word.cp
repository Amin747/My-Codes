class TrieNode{
    public:
    TrieNode* children[26];
    bool end;
};

class WordDictionary {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root;
        for (int i=0; i<word.length(); i++){
            if(!p->children[word[i]-'a']){
                p->children[word[i]-'a'] = new TrieNode();
            }
            p = p->children[word[i]-'a'];
        }
        p->end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return helper(root, word, 0);
    }
    
    bool helper(TrieNode* cur, string word, int index){
        if (index==word.length()) return cur->end;
        if (word[index]=='.'){
            for (int j=0; j<=25; j++){
                if (cur->children[j]!=NULL && helper(cur->children[j], word, index+1)){
                    return true;
                }
            }
            return false;
        }
        else{
            return cur->children[word[index]-'a']!=NULL && helper(cur->children[word[index]-'a'], word, index+1);
            }
        return true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
