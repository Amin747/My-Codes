class TrieNode{
  public:
    TrieNode* children[26];
    bool end;
};


class Trie {
    TrieNode* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for(int i=0; i<word.length(); i++){
            if(p->children[word[i]-'a']==NULL){
                p->children[word[i]-'a'] = new TrieNode();
            }
            p = p->children[word[i]-'a'];
        }
        p->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        cout << "searching for " << word << endl;
        for(int i=0; i<word.length(); i++){
            if (p->children[word[i]-'a']){
                cout << "found " << word[i] << endl;
                p = p->children[word[i]-'a'];
            }
            else if(p!=NULL && p->children[word[i]-'a'] && p->end==true) return true;
            else return false;
        }
        if (!p->end) return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(int i=0; i<prefix.length(); i++){
            if (p!=NULL && p->children[prefix[i]-'a']){
                p = p->children[prefix[i]-'a'];
            }
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
