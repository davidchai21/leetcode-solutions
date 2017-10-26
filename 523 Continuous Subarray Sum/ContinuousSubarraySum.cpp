class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (k==0) {
            for (int i=0;i<nums.size()-1;i++) {
                if (nums[i]==0 && nums[i+1]==0) return true;
            }
            return false;
        }
        if (k<0) k=-k;
        unordered_map<int,int> m;
        m[0]=-1;
        long sum=0;
        for (int i=0;i<nums.size();i++) {
            sum=(sum+(long)nums[i])%k;
            if (m.find(sum)==m.end()) m[sum]=i;
            else {
                if (i-m[sum]>1) return true;
            }
        }
        return false;
    }
};