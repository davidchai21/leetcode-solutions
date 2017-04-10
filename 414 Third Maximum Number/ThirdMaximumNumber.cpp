class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<long> res={LONG_MIN, LONG_MIN, LONG_MIN};
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i]>res[0] && nums[i]!=res[1] && nums[i]!=res[2])
            {res[0]=nums[i]; sort(res.begin(),res.end());}
        }
        return res[0]==LONG_MIN?res[2]:res[0];
    }
};