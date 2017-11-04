class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int> > m;
        int max_size=0;
        for (int i=0;i<nums.size();i++) {
            m[nums[i]].push_back(i);
            max_size=max(max_size,(int)m[nums[i]].size());
        }
        int res=INT_MAX;
        for (auto p:m) {
            if (p.second.size()==max_size) res=min(res,p.second.back()-p.second[0]+1);
        }
        return res;
    }
};