class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1);
        res[0]=0;
        if (num==0) return res;
        res[1]=1;
        if (num==1) return res;
        int n=log2(num);
        for (int i=1;i<=n;i++)
        {
            int t=pow(2,i);
            for (int j=t;j<=num && j<pow(2,i+1);j++)
            {
                res[j]=res[j-t]+1;
            }
        }
        return res;
    }
};