class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int n=nums.size();
        if (n<4) return false;
        int sum=accumulate(nums.begin(),nums.end(),0);
        if (sum%4) return false;
        sort(nums.begin(),nums.end(),greater<int>());
        vector<int> l(4,0);
        return helper(nums,l,sum/4,0);
    }
    bool helper(const vector<int> nums, vector<int>& l, const int target, int pos) {
        if (pos==nums.size()) {
            return l[1]==l[2] && l[2]==l[3] && l[0]==l[3];
        }
        for (int i=0;i<4;i++) {
            if (l[i]+nums[pos]>target) continue;
            int j=i;
        while (--j>=0) {
            if (l[j]==l[i]) break;
        }
        if (j!=-1) continue;
            l[i]+=nums[pos];
            if (helper(nums,l,target,pos+1)) return true;
            l[i]-=nums[pos];
        }
        return false;
    }
};