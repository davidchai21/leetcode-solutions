class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        if (numRows<1) return res;
        vector<int> a={1};
        res.push_back(a);
        for (int i=2;i<=numRows;i++)
        {
            vector<int> t(i,1);
            for (int j=1;j<i-1;j++)
            {
                t[j]=res[i-2][j-1]+res[i-2][j];
            }
            res.push_back(t);
        }
        return res;
    }
};