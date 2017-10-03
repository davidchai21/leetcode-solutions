class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int res=0;
        int n=nums.size();
        int cur=0;
        unordered_map<int,int> m;
        for (int i=0;i<n;i++) {
            cur+=nums[i];
            if (cur==k) res=max(i+1,res);
            else if (m.find(cur-k)!=m.end()) {
                res=max(res,i-m[cur-k]);
            }
            if (m.find(cur)==m.end()) m[cur]=i;
        }
        return res;
    }
};