class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int> > t;
        vector<int> res;
        if (k==0) return res;
        unordered_map<int,int> m;
        for (int a:nums) m[a]++;
        for (auto& a:m)
        {
            t.push_back(make_pair(a.first,a.second));
        }
        sort(t.begin(),t.end(),[](pair<int,int> a,pair<int,int> b){return a.second>b.second;});
        for (int i=0;i<k;i++)
        {
            res.push_back(t[i].first);
        }
        return res;
    }
};