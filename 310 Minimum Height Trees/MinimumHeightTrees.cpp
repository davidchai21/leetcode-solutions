class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        if (edges.size()!=n-1) return res;
        vector<int> indegree(n,0);
        vector<unordered_set<int> > s(n);
        for (int i=0;i<edges.size();i++) {
            s[edges[i].first].insert(edges[i].second);
            s[edges[i].second].insert(edges[i].first);
        }
        for (int i=0;i<n;i++) indegree[i]=s[i].size();
        for (int k=n;k>2;) {
            vector<int> t;
            for (int i=0;i<n;i++) {
                if (indegree[i]==1) {
                    t.push_back(i);
                    k--;
                    indegree[i]=-1;
                }
            }
            for (int i:t) {
                for (auto p:s[i]) indegree[p]--;
            }
        }
        for (int i=0;i<n;i++) {
            if (indegree[i]>=0) res.push_back(i); 
        }
        return res;
    }
};