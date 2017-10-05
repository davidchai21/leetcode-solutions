class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res=0;
        int one=0;
        int zero=0;
        unordered_map<int,int> m;
        for (int i=0;i<nums.size();i++) {
            if (nums[i]==0) zero++;
            else if (nums[i]==1) one++;
            int t=zero-one;
            if (t==0) res=max(res,i+1);
            else {
                if (m[t]==0) m[t]=i+1;
                else res=max(res,i+1-m[t]);
            }
        }
        return res;
    }
};