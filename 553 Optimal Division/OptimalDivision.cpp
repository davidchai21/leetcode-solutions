class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n=nums.size();
        if (n<1) return "";
        if (n==1) return to_string(nums[0]);
        if (n==2) return to_string(nums[0])+"/"+to_string(nums[1]);
        string res="";
        for (int i=n-1;i>1;i--)
        {
            res="/"+to_string(nums[i])+res;
        }
        res=to_string(nums[0])+"/("+to_string(nums[1])+res+")";
        return res;
    }
};