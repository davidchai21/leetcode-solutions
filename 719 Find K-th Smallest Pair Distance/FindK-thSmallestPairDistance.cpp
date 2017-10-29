class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        const int N=1000000;
        vector<int> res(N,0);
        for (int i=0;i<nums.size();i++) {
            for (int j=i+1;j<nums.size();j++) {
                res[abs(nums[i]-nums[j])]++;
            }
        }
        int i=0;
        while (k-res[i]>0) k-=res[i++];
        return i;
    }
};