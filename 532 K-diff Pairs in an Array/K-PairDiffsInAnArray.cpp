class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k<0) return 0;
        int res=0;
        unordered_map<int,int> m;
        for (int a:nums)
        {
            m[a]++;
        }
        if (k==0)
        {
            for (auto i=m.begin();i!=m.end();i++)
            {
                if (i->second>1) res++;
            }
        }
        else
        {
            for (auto i=m.begin();i!=m.end();i++)
            {
                if (m.find(i->first+k)!=m.end()) res++;
            }
        }
        return res;
    }
};