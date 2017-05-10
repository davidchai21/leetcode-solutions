class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n=A.size();
        if (n<3) return 0;
        vector<int> res(n,0);
        int s=0;
        for (int i=2;i<n;i++)
        {
            if (A[i]+A[i-2]==2*A[i-1])
            {
                res[i]=res[i-1]+1;
                s+=res[i];
            }
        }
        return s;
    }
};