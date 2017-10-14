class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> save(1001,0);
        for (int i=0;i<n;i++) {
            save[i]=i;
        }
        vector<int> res;
        for (int i=0;i<n;i++) {
            int a=edges[i][0];
            int b=edges[i][1];
            while (a!=save[a]) a=save[a];
            while (b!=save[b]) b=save[b];
            if (a!=b) save[a]=b;
            else res=edges[i];
        }
        return res;
    }
};