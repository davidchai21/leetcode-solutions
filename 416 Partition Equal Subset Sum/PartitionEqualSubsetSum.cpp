class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return false;
        int max=accumulate(nums.begin(),nums.end(),0);
        if (max%2) return false;
        max/=2;
        vector<bool> res(max+1,0);
        res[0]=true;
        for (int i=0;i<n;i++)
        {
            for (int j=max;j-nums[i]>=0;j--)
            {
                res[j]=res[j-nums[i]] || res[j];
            }
        }
        return res[max];
    }
};