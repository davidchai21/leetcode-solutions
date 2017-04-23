class Solution {
public:
    int countPrimes(int n) {
        if (n<3) return 0;
        vector<bool> res(n,true);
        res[0]=res[1]=false;
        for (int i=2;i<=sqrt(n);i++)
        {
            if (res[i])
            {
                for (int j=i*i;j<n;j+=i)
                {res[j]=false;}
            }
        }
        return count(res.begin(),res.end(),true);
    }
};