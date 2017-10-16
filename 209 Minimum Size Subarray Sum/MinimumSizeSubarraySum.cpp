class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size()==0) return 0;
        int i=0;
        int j=0;
        int res=INT_MAX;
        int sum=nums[0];
        while (j<nums.size()) {
            if (sum>=s) {
                res=min(res,j-i+1);
                sum-=nums[i++];
            }
            else {
                sum+=nums[++j];
            }
        }
        return res==INT_MAX?0:res;
    }
};