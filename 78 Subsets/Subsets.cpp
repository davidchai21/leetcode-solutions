class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> t;
        helper(res,t,nums,0);
        return res;
    }
    void helper(vector<vector<int> >& res, vector<int>& t, vector<int> nums, int index) {
        res.push_back(t);
        for (int i=index;i<nums.size();i++) {
            t.push_back(nums[i]);
            helper(res,t,nums,i+1);
            t.pop_back();
        }
    }
};