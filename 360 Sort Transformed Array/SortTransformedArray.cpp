class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n=nums.size();
        vector<int> res(n,c);
        int i=0;
        int j=n-1;
        if (a<0) {
            int index=0;
            while (i<=j) {
                int x=helper(a,b,nums[i]);
                int y=helper(a,b,nums[j]);
                if (x<y) {
                    res[index++]+=x;
                    i++;
                }
                else {
                    res[index++]+=y;
                    j--;
                }
            }
        }
        else {
            int index=n-1;
            while (i<=j) {
                int x=helper(a,b,nums[i]);
                int y=helper(a,b,nums[j]);
                if (x>y) {
                    res[index--]+=x;
                    i++;
                }
                else {
                    res[index--]+=y;
                    j--;
                }
            }
        }
        return res;
    }
    int helper(int a, int b, int x) {
        return a*x*x+b*x;
    }
};