class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n=A.size();
        if (n==0) return 0;
        int res=0;
        unordered_map<int,int> a,b;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                a[A[i]+B[j]]++;
                b[C[i]+D[j]]++;
            }
        }
        
        for (auto it=a.begin();it!=a.end();it++)
        {
            auto u=b.find(-it->first);
            if (u!=b.end())
            {
                res+=u->second*it->second;
            }
        }
        return res;
    }
};