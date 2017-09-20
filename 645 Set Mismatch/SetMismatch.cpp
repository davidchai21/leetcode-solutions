class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup;
        int mis;
        for (int i=0;i<nums.size();i++)
        {
            int t=abs(nums[i])-1;
            if (nums[t]>0) nums[t]=-nums[t];
            else dup=t+1;
        }
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i]>0) mis=i+1;
        }
        vector<int> res;
        res.push_back(dup);
        res.push_back(mis);
        return res;
    }
};