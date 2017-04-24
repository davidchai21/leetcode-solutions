class Solution {
public:
    int nthUglyNumber(int n) {
        if (n<2) return n;
        vector<int> res(n,0);
        int a=0,b=0,c=0;
        res[0]=1;
        for (int i=1;i<n;i++)
        {
            int t=min(min(2*res[a],3*res[b]),5*res[c]);
            res[i]=t;
            if (t==2*res[a]) a++;
            if (t==3*res[b]) b++;
            if (t==5*res[c]) c++;
        }
        return res[n-1];
    }
};