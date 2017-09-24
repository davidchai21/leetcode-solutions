class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        while (left<n && nums[left]<=nums[left+1]) left++;
        while (right>=0 && nums[right]>=nums[right-1]) right--;
        if (left<right) {
            int vmin=nums[left];
            int vmax=nums[right];
            for (int i=left;i<=right;i++)
            {
                if (nums[i]<vmin) vmin=nums[i];
                if (nums[i]>vmax) vmax=nums[i];
            }
            while (left>=0 && nums[left]>vmin) left--;
            while (right<=n-1 && nums[right]<vmax) right++;
            return right-left-1;
        }
        return 0;
    }
};