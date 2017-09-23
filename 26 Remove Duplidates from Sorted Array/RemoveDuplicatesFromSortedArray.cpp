class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if (n<2) return n;
        int i=0;
        int j=1;
        int res=1;
        while (i<n && j<n)
        {
            while (j<n && nums[i]==nums[j]) j++;
            if (j<n) {
                swap(nums[i+1],nums[j]);
                i++;j++;res++;
            }
        }
        return res;
    }
};