class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k<=0) return false;
        k=(k>nums.size()?nums.size():k);
        set<long long> s;
        for (int i=0;i<nums.size();i++)
        {
            if (i>k) s.erase((long long)nums[i-k-1]);
            auto p=s.lower_bound((long long)nums[i]-(long long)t);
            if (abs((long long)nums[i]-(long long)*p)<=(long long)t && p!=s.end()) return true;
            s.insert((long long)nums[i]);
        }
        return false;
    }
};