class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size()<2) return false;
        unordered_map<int,int> m;
        for (int a:nums)
        {
            if (m[a]!=0) return true;
            m[a]++;
        }
        return false;
    }
};