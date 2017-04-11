class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> m;
        for (int i=0;i<nums.size();i++)
        {
            int t=target-nums[i];
            if (m.find(t)!=m.end())
            {
                res.push_back(m[t]);
                res.push_back(i);
                break;
            }
            m[nums[i]]=i;
        }
        return res;
    }
};