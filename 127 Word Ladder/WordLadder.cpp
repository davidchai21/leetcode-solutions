class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        if (s.find(endWord)==s.end()) return 0;
        queue<pair<string,int> > q;
        q.push({beginWord,1});
        s.erase(beginWord);
        while (!q.empty()) {
            pair<string,int> t=q.front();
            q.pop();
            for (auto it=s.begin();it!=s.end();) {
                if (diff(*it,t.first)==1) {
                    if ((*it)==endWord) return t.second+1;
                    q.push({*it,t.second+1});
                    it=s.erase(it);
                }
                else it++;
            }
        }
        return 0;
    }
    int diff(string a, string b) {
        if (a.size()!=b.size()) return -1;
        int res=0;
        for (int i=0;i<a.size();i++) {
            if (a[i]!=b[i]) res++;
        }
        return res;
    }
};