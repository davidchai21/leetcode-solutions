class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int tmin=res;
        int tmax=res;
        for (int i=1;i<nums.size();i++) {
            if (nums[i]<0) swap(tmin,tmax);
            tmax=max(nums[i],nums[i]*tmax);
            tmin=min(nums[i],nums[i]*tmin);
            res=max(res,tmax);
        }
        return res;
    }
};