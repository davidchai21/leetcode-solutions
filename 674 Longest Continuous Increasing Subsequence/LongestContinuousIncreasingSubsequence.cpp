class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size()==0) return 0;
        int res=1;
        int count=1;
        for (int i=0;i<nums.size()-1;i++)
        {
            if (nums[i+1]>nums[i]) count++;
            else {
                res=max(res,count);
                count=1;
            }
        }
        res=max(res,count);
        return res;
    }
};