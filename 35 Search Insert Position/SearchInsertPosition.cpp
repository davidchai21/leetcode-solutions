class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        if (n==0) return 0;
        if (target>nums[n-1]) return n;
        int i=0,j=n-1;
        while (i<j)
        {
            int mid=i+(j-i)/2;
            if (nums[mid]>target) j=mid;
            else if (nums[mid]<target) i=mid+1;
            else return mid;
        }
        return i;
    }
};