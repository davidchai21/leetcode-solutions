class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0;
        int t=0;
        int i=0;
        while (i<nums.size())
        {
            if (nums[i]==1)
            {
                t++;
            }
            else
            {
                if (t>res) res=t;
                t=0;
            }
            i++;
        }
        if (t>res) res=t;
        return res;
    }
};