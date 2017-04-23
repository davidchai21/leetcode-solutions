class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];
        if (n==2) return max(nums[0],nums[1]);
        int pre=0, cur1=0, cur2=0;
        for (int i=0;i<n-1;i++)
        {
            int t=pre;
            pre=cur1;
            cur1=max(t+nums[i],cur1);
        }
        pre=0;
        for (int i=1;i<n;i++)
        {
            int t=pre;
            pre=cur2;
            cur2=max(t+nums[i],cur2);
        }
        return max(cur1,cur2);
    }
};