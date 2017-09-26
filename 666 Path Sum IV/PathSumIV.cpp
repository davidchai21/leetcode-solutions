class Solution {
public:
    int pathSum(vector<int>& nums) {
        vector<vector<int>> m(5,vector<int>(8,0));
        for (int i=0;i<nums.size();i++)
        {
            int a=nums[i]/100;
            int b=(nums[i]%100)/10-1;
            int c=nums[i]%10;
            m[a][b]=m[a-1][b/2]+c;
        }
        int res=0;
        for (int i=1;i<5;i++)
        {
            for (int j=0;j<8;j++) {
                if (i==4 || m[i][j] && !m[i+1][2*j] && !m[i+1][2*j+1]) res+=m[i][j];
            }
        }
        return res;
    }
};