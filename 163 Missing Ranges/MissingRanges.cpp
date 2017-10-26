class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        long low=lower;
        long high=lower;
        for (int i=0;i<=nums.size();i++) {
            low=i==0?low:(long)nums[i-1]+1;
            high=i==nums.size()?(long)upper:(long)nums[i]-1;
            if (low==high) res.push_back(to_string(low));
            else if (low<high) res.push_back(to_string(low)+"->"+to_string(high));
        }
        return res;
    }
};