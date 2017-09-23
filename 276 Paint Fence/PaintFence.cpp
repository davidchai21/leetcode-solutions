class Solution {
public:
    int numWays(int n, int k) {
        if (k==0 || n==0) return 0;
        if (k==1) return (n<3)?1:0;
        vector<int> same(n);
        vector<int> diff(n);
        same[0]=0;
        diff[0]=k;

        for (int i=1;i<n;i++)
        {
            same[i]=diff[i-1];
            diff[i]=(k-1)*(diff[i-1]+same[i-1]);
        }
        return diff[n-1]+same[n-1];
    }
};