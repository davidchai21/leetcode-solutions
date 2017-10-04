class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        if (n<3) return 0;
        sort(nums.begin(),nums.end());
        int i=0;
        while (nums[i]<=0) i++;
        for (;i<n-2;i++) {
            int k=i+2;
            for (int j=i+1;j<n-1;j++) {
                while (k<n && nums[k]<nums[i]+nums[j]) k++;
                res+=k-j-1;
            }
        }
        return res;
    }
};