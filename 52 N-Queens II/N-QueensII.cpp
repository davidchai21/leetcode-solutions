class Solution {
public:
    int totalNQueens(int n) {
        int res=0;
        vector<string> part;
        helper(res,n,part,0);
        return res;
    }
    void helper(int& res, int N, vector<string>& part, int row) {
        if (row>=N) {
            res++;
            return;
        }
        for (int i=0;i<N;i++) {
            if (check(part,i,N)) {
                part.push_back(string(i,'.')+"Q"+string(N-i-1,'.'));
                helper(res,N,part,row+1);
                part.pop_back();
            }
        }
    }
    bool check(vector<string> part, int pos, int N) {
        if (part.empty()) return true;
        int n=part.size();
        for (int i=0;i<n;i++) {
            if (part[i][pos]=='Q' || pos-n+i>=0 && part[i][pos-n+i]=='Q' || pos+n-i<N && part[i][pos+n-i]=='Q') return false;
        }
        return true;
    }
};