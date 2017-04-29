class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int> > res;
        if (num.size()<3) return res;
        sort(num.begin(),num.end());
        for (int i=0;i<num.size()-2;i++)
        {
            if (num[i]==num[i-1] && i>0) continue;
            int sum=-num[i];
            int m=i+1, n=num.size()-1;
            while (m<n)
            {
                if (num[m]+num[n]>sum) n--;
                else if (num[m]+num[n]<sum) m++;
                else
                {
                    res.push_back(vector<int>{num[i],num[m],num[n]});
                    while (num[m]==num[m+1]) m++;
                    while (num[n]==num[n-1]) n--;
                    m++; n--;
                }
            }
        }
        return res;
    }
};
