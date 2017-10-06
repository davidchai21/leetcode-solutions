class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left=0;
        int right=nums.size()-1;
        while (1) {
            int pos=partition(nums,left,right);
            if (pos==k-1) return nums[k-1];
            if (pos>k-1) right=pos-1;
            else left=pos+1;
        }
    }
    int partition(vector<int>& nums, int begin, int end) {
        int t=nums[begin];
        int l=begin+1;
        int r=end;
        while (l<=r) {
            if (nums[l]<t && nums[r]>t) {
                swap(nums[l++],nums[r--]);
            }
            if (nums[l]>=t) l++;
            if (nums[r]<=t) r--;
        }
        swap(nums[begin],nums[r]);
        return r;
    }
};