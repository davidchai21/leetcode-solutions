class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        for (int i=0;i<dictionary.size();i++) {
            string t=dictionary[i][0]+to_string(dictionary[i].size())+dictionary[i].back();
            m[t].insert(dictionary[i]);
        }
    }
    
    bool isUnique(string word) {
        string t=word[0]+to_string(word.size())+word.back();
        return m[t].count(word)==m[t].size();
    }
private:
    unordered_map<string,unordered_set<string> > m;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */