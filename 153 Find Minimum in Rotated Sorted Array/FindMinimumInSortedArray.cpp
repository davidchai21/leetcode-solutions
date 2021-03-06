class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        int i=0,j=nums.size()-1;
        while (i<j)
        {
            if (nums[i]<nums[j]) return nums[i];
            int mid=i+(j-i)/2;
            if (nums[mid]>=nums[i]) i=mid+1;
            else j=mid;
        }
        return nums[i];
    }
};