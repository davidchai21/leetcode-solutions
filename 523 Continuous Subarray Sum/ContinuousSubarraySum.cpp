class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int res=0;
        int pre=0;
        unordered_set<int> s;
        for (int i=0;i<nums.size();i++)
        {
            res+=nums[i];
            int t=(k==0)?res:res%k;
            if (s.count(t)) return true;
            s.insert(pre);
            pre=t;
        }
        return false;
    }
};