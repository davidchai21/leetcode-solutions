class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string,multiset<string> > m;
        stack<string> s;
        vector<string> res;
        if (tickets.empty()) return res;
        for (pair<string,string> p:tickets) {
            m[p.first].insert(p.second);
        }
        s.push("JFK");
        while (!s.empty()) {
            string t=s.top();
            if (m[t].empty()) {
                res.push_back(t);
                s.pop();
            }
            else {
                s.push(*(m[t].begin()));
                m[t].erase(m[t].begin());
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};