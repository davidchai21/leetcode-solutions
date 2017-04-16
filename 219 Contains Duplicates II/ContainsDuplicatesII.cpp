class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k<=0) return false;
        if (k>nums.size()) k=nums.size();
        unordered_set<int> s;
        for (int i=0;i<nums.size();i++)
        {
            if (i>k) s.erase(nums[i-k-1]);
            if (!s.insert(nums[i]).second) return true;
        }
        return false;
    }
};