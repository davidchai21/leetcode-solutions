class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int> > res(n,vector<int>(n,0));
        for (int i=n-1;i>=0;i--) {
            for (int j=i;j<n;j++) {
                if (i==j) res[i][j]=nums[i];
                else {
                    res[i][j]=max(nums[i]-res[i+1][j],nums[j]-res[i][j-1]);
                }
            }
        }
        return res[0][n-1]>=0;
    }
};