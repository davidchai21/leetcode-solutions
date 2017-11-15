class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        vector<string> res;
        for (string word:words) {
            m[word]++;
            if (m[word]==1) res.push_back(word);
        }
        sort(res.begin(),res.end(),[&](string a, string b){return m[a]>m[b] || m[a]==m[b] && a<b;});
        return vector<string>(res.begin(),res.begin()+(res.size()<k?res.size():k));
    }
};