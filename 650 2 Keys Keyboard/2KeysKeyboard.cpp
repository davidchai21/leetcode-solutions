class Solution {
public:
    int minSteps(int n) {
        if (n<2) return 0;
        vector<int> res(n+1,0);
        res[0]=0;
        res[1]=0;
        for (int i=2;i<=n;i++) {
            if (i%2==0) res[i]=2+res[i/2];
            else {
                int s=sqrt(i);
                int ans=INT_MAX;
                for (int j=1;j<=s;j++) {
                    if (i%j==0) {
                        ans=min(ans,res[j]+i/j);
                        if (j!=1) ans=min(ans,res[i/j]+j);
                    }
                }
                res[i]=ans;
            }
        }
        return res[n];
    }
};