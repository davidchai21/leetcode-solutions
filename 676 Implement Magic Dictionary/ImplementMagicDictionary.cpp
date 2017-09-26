class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        m.clear();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (int i=0;i<dict.size();i++) {
            m[dict[i].size()].push_back(dict[i]);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int n=word.size();
        if (m.find(n)==m.end()) return false;
        for (int i=0;i<m[n].size();i++)
        {
            bool flag=false;
            int j=0;
            for (;j<n;j++) {
                if (m[n][i][j]!=word[j]) {
                    if (flag) break;
                    flag=true;
                }
            }
            if (flag && j==n) return true;
        }
        return false;
    }
private:
    unordered_map<int,vector<string> > m;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */