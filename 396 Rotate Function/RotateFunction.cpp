class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n=A.size();
        int sum=0;
        int f=0;
        for (int i=0;i<n;i++) {sum+=A[i]; f+=i*A[i];}
        int k;
        int res=f;
        for (int i=1;i<n;i++)
        {
            k=sum+f-n*A[n-i];
            res=max(res,k);
            f=k;
        }
        return res;
    }
};