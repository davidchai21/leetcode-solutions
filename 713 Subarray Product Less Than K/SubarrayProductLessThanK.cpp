class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k==0) return 0;
        int res=0;
        int val=nums[0];
        int i=0;
        int j=0;
        while (j<nums.size()) {
            while (i<=j && val>=k) val/=nums[i++];
            res+=j-i+1;
            j++;
            if (j<nums.size()) val*=nums[j];
        }
        return res;
    }
};