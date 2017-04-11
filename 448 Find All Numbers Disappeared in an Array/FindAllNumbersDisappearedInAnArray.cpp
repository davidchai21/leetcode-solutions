class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int i=0;
        while (i<nums.size())
        {
            if (nums[i]!=nums[nums[i]-1])
            {
                swap(nums[i],nums[nums[i]-1]);
            }
            else i++;
        }
        for (int j=0;j<nums.size();j++)
        {
            if (nums[j]!=j+1) res.push_back(j+1);
        }
        return res;
    }
};