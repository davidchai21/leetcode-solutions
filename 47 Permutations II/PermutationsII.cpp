class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> t;
        vector<bool> visited(nums.size(),false);
        helper(res,t,nums,visited);
        return res;
    }
    void helper(vector<vector<int> >& res, vector<int>& t, vector<int> nums, vector<bool>& visited) {
        if (t.size()==nums.size()) {
            res.push_back(t);
            return;
        }
        unordered_set<int> s;
        for (int i=0;i<nums.size();i++) {
            if (s.find(nums[i])==s.end() && visited[i]==false) {
                t.push_back(nums[i]);
                visited[i]=true;
                helper(res,t,nums,visited);
                visited[i]=false;
                t.pop_back();
                s.insert(nums[i]);
            }
        }
    }
};