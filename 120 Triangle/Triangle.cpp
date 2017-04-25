class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if (n<1) return 0;
        vector<int> res(triangle.back());
        for (int i=n-2;i>=0;i--)
        {
            for (int j=0;j<triangle[i].size();j++)
            {
                res[j]=triangle[i][j]+min(res[j],res[j+1]);
            }
        }
        return res[0];
    }
};