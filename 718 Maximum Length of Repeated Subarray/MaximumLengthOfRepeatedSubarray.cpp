class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if (A.empty() || B.empty()) return 0;
        vector<int> t(B.size()+1,0);
        int res=0;
        for (int i=1;i<=A.size();i++) {
            vector<int> now=t;
            for (int j=1;j<=B.size();j++) {
                if (A[i-1]==B[j-1]) {
                    t[j]=now[j-1]+1;
                    res=max(res,t[j]);
                }
                else t[j]=0;
            }
        }
        return res;
    }
};