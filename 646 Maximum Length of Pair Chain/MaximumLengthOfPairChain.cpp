class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        if (n<2) return n;
        sort(pairs.begin(),pairs.end(),[](vector<int> a,vector<int> b){return a[1]<b[1] || a[1]==b[1] && a[0]<b[0];});
        int k=0;
        int res=1;
        for (int i=1;i<n;i++) {
            if (pairs[i][0]>pairs[k][1]) {
                res++;
                k=i;
            }
        }
        return res;
    }
};