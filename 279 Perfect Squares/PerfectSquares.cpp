class Solution {
public:
    int numSquares(int n) {
        vector<int> res(n+1,INT_MAX);
        res[0]=0;
        for (int i=1;i<=n;i++)
        {
            int a=sqrt(i);
            for (int j=a;j>0;j--)
            {
                if (res[i]>res[i-j*j]) res[i]=res[i-j*j];
            }
            res[i]++;
        }
        return res[n];
    }
};