class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> one(32,0);
        for (int n:nums) {
            int i=0;
            while (n>0) {
                one[i]+=(n & 1);
                n>>=1;
                i++;
            }
        }
        int res=0;
        for (int n:one) {
            res+=(nums.size()-n)*n;
        }
        return res;
    }
};