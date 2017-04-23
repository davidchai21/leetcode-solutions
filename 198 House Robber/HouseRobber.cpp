class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];
        if (n==2) return max(nums[0],nums[1]);
        vector<int> res(n,0);
        res[0]=nums[0];
        res[1]=nums[1];
        res[2]=max(nums[1],nums[0]+nums[2]);
        for (int i=3;i<n;i++)
        {
            res[i]=max(res[i-2],res[i-3])+nums[i];
        }
        return max(res[n-1],res[n-2]);
    }
};