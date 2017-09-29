class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        if (n<2) return n;
        nums.insert(nums.begin(),0);
        n++;
        int i=0;
        int t=1;
        int res=0;
        while (t<n && nums[t]==1) t++;
        if (t>=n) return n-1;
        while (i<n){
            int j=t+1;
            while (j<n && nums[j]==1) j++;
            res=max(res,j-i-1);
            i=t;
            t=j;
            if (j>=n) break;
        }
        return res;
    }
};