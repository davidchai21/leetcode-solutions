class Solution {
public:
    int uniquePaths(int m, int n) {
        return com(m,n);
    }
private:
    long com(int m,int n)
    {
        long res=1;
        for (int i=1;i<m;i++)
        {
            res=res*(n-1+i)/i;
        }
        return res;
    }
};