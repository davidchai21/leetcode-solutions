class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left=0;
        int right=nums.size()-1;
        while (left<right) {
            int mid=left+(right-left)/2+1;
            if (nums[mid]>=nums[left]) left=mid;
            else right=mid-1;
        }
        if (target>=nums[0]) return helper(nums,0,left,target);
        return helper(nums,left+1,nums.size()-1,target);
    }
    int helper(vector<int> nums, int left, int right, int target) {
        while (left<=right) {
            int mid=left+(right-left)/2;
            if (nums[mid]==target) return mid;
            else if (nums[mid]<target) left=mid+1;
            else right=mid-1;
        }
        return -1;
    }
};