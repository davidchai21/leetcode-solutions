class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n=nums.size();
        if (n==0) return res;
        int i=0;
        while (i<n) {
            int j=i+1;
            while (j<n && nums[j]-nums[i]==j-i) j++;
            if (j==i+1) res.push_back(to_string(nums[i]));
            else {
                res.push_back(to_string(nums[i])+"->"+to_string(nums[j-1]));
            }
            i=j;
        }
        return res;
    }
};