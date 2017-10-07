class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> res(n,0);
        for (int i=0;i<n;i++) res[i]=i;
        for (int i=0;i<edges.size();i++) {
            int a=edges[i].first;
            int b=edges[i].second;
            while (a!=res[a]) a=res[a];
            while (b!=res[b]) b=res[b];
            if (a==b) return false;
            res[a]=b;
        }
        return edges.size()==n-1;
    }
};