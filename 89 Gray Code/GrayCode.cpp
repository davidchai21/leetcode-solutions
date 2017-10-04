class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(pow(2,n),0);
        if (n==0) return res;
        res[1]=1;
        for (int i=2;i<=n;i++) {
            int k=pow(2,i-1);
            for (int j=1;j<=k;j++) {
                res[k+j-1]=k+res[k-j];
            }
        }
        return res;
    }
};