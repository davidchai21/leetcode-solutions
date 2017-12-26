class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size()==1) return 0;
        int first=nums[0];
        int second=INT_MIN;
        int index=0;
        for (int i=1;i<nums.size();i++) {
            if (nums[i]>=first) {
                second=first;
                first=nums[i];
                index=i;
            }
            else if (nums[i]>=second) {
                second=nums[i];
            }
        }
        return first>=2*second?index:-1;
    }
};