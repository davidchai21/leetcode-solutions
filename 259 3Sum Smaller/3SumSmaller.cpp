class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n=nums.size();
        if (n<3) return 0;
        sort(nums.begin(),nums.end());
        int res=0;
        for (int i=0;i<n-2;i++) {
            int j=i+1;
            int k=n-1;
            while (j<k) {
                if (nums[j]+nums[k]<target-nums[i]) {
                    res+=k-j;
                    j++;
                }
                else k--;
            }
        }
        return res;
    }
};