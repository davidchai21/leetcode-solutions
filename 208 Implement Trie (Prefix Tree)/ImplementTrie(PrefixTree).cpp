class TrieNode {
public:
    char c;
    TrieNode* children[26];
    bool end;
    TrieNode(): end(false) {memset(children,0,sizeof(children));}
    TrieNode(char a): c(a), end(false) {memset(children,0,sizeof(children));};
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur=root;
        for (int i=0;i<word.size();i++) {
            if (!cur->children[word[i]-'a']) cur->children[word[i]-'a']=new TrieNode(word[i]);
            cur=cur->children[word[i]-'a'];
        }
        cur->end=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur=root;
        for (int i=0;i<word.size();i++) {
            if (cur->children[word[i]-'a']) cur=cur->children[word[i]-'a'];
            else return false;
        }
        return cur->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur=root;
        for (int i=0;i<prefix.size();i++) {
            if (cur->children[prefix[i]-'a']) cur=cur->children[prefix[i]-'a'];
            else return false;
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */