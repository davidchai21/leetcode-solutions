class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if (m==0) return 0;
        int n=matrix[0].size();
        if (n==0) return 0;
        int area=INT_MIN;
        vector<int> res(n,0);
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (matrix[i][j]=='1') 
                {
                    res[j]++;
                }
                else res[j]=0;
            }
            area=max(area,helper(res));
        }
        return area;
    }
private:
    int helper(vector<int>& a)
    {
        a.push_back(0);
        stack<int> s;
        int res=0;
        for (int i=0;i<a.size();i++)
        {
            if (s.empty() || a[i]>=a[s.top()]) s.push(i);
            else
            {
                int t=a[s.top()];
                s.pop();
                res=max(res,t*(s.empty()?i:i-1-s.top()));
                i--;
            }
        }
        return res;
    }
};