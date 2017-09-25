class Solution {
public:
    int countArrangement(int N) {
        vector<int> a;
        for (int i=1;i<=N;i++) a.push_back(i);
        return helper(N,a);
    }
    int helper(int n, vector<int> a) {
        if (n<=0) return 1;
        int res=0;
        for (int i=0;i<n;i++)
        {
            if (a[i]%n==0 || n%a[i]==0) {
                swap(a[i],a[n-1]);
                res+=helper(n-1,a);
                swap(a[i],a[n-1]);
            }
        }
        return res;
    }
};