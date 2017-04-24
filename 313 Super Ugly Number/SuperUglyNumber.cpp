class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n<2) return n;
        int k=primes.size();
        vector<int> counter(k,0);
        vector<int> res(n,0);
        res[0]=1;
        for (int i=1;i<n;i++)
        {
            int t=INT_MAX;
            for (int j=0;j<k;j++)
            {
                t=t>(res[counter[j]]*primes[j])?res[counter[j]]*primes[j]:t;
            }
            for (int j=0;j<k;j++)
            {
                if (t==res[counter[j]]*primes[j]) counter[j]++;
            }
            res[i]=t;
        }
        return res[n-1];
    }
};