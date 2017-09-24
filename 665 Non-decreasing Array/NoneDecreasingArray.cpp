class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        if (n<3) return true;
        bool flag=false;
        if (nums[1]<nums[0]) {
            flag=true;
            nums[0]=nums[1];
        }
        for (int i=1;i<n-1;i++)
        {
            if (nums[i+1]<nums[i]) {
                if (flag) return false;
                else {
                    flag=true;
                    if (nums[i+1]>=nums[i-1]) nums[i]=nums[i-1];
                    else nums[i+1]=nums[i];
                }
            }
        }
        return true;
    }
};