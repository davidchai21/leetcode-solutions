class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int i=0;
        int k=0;
        for (;i<nums.size();i++) {
            if (k*2==sum-nums[i]) return i;
            k+=nums[i];
        }
        return -1;
    }
};