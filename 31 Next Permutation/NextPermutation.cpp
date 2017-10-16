class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        while (i>=0 && nums[i]>=nums[i+1]) i--;
        if (i<0) sort(nums.begin(),nums.end());
        else {
            int j=i+1;
            while (j<nums.size() && nums[j]>nums[i]) j++;
            swap(nums[i],nums[--j]);
            sort(nums.begin()+i+1,nums.end());
        }
    }
};