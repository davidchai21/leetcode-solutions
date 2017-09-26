
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        int res=0;
        visited.resize(n,false);
        if (n<2) return n;
        for (int i=0;i<n;i++) {
            if (!visited[i]) {
                visited[i]=true;
                res+=helper(M,n,i);
            }
        }
        return res;
    }
    int helper(vector<vector<int> > M,int n, int k) {
        int res=1;
        for (int i=0;i<n;i++) {
            if (!visited[i] && M[i][k]) {
                res++;
                visited[i]=true;
                helper(M,n,i);
            }
        }
        return res>0;
    }
private:
    vector<bool> visited;
};