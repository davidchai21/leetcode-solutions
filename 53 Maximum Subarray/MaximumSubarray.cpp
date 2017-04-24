class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=INT_MIN;
        int pre=INT_MIN;
        for (int a:nums)
        {
            int cur=(pre<0)?a:pre+a;
            res=max(cur,res);
            pre=cur;
        }
        return res;
    }
};