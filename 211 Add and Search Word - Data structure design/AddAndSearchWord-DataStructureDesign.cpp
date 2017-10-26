class TrieNode {
public:
    char c;
    bool end;
    TrieNode* children[26];
    TrieNode(char t): c(t), end(false) {
        memset(children,0,sizeof(children));
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {}
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* cur=root;
        for (int i=0;i<word.size();i++) {
            if (!cur->children[word[i]-'a']) cur->children[word[i]-'a']=new TrieNode(word[i]-'a');
            cur=cur->children[word[i]-'a'];
        }
        cur->end=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return helper(word.c_str(),root);
    }
    bool helper(const char* t, TrieNode* node) {
        if (!node) return false;
        if (*t=='\0') return node->end;
        else if (*t!='.') {
            return helper(t+1,node->children[*t-'a']);
        }
        else {
            for (int i=0;i<26;i++) {
                if (helper(t+1,node->children[i])) return true;
            }
            return false;
        }
    }
private:
    TrieNode* root=new TrieNode('a');
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */