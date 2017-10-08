
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n=nums.size();
        if (n<7) return false;
        int s=0;
        vector<int> sum(n,0);
        for (int i=0;i<n;i++) {
            s+=nums[i];
            sum[i]=s;
        }
        int start=0;
        for (;start<n-3;start++) {
            for (int end=n-2;end>start+3;end--) {
                if (sum.back()-sum[end]==sum[start]) {
                    int f=sum.back()-4*sum[start]-nums[start+1]-nums[end];
                    for (int k=start+3;k<end-1;k++) {
                        if (nums[k]==f) return true;
                    }
                }
            }
        }
        return false;
    }
};