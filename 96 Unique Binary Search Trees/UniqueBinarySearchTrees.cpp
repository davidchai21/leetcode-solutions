class Solution {
public:
    int numTrees(int n) {
        if (n<2) return 1;
        vector<int> res(n+1,1);
        for (int i=2;i<=n;i++) {
            int t=0;
            for (int j=0;j<i;j++) {
                t+=res[j]*res[i-j-1];
            }
            res[i]=t;
        }
        return res[n];
    }
};