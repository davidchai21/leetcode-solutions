class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=accumulate(nums.begin(),nums.begin()+k,0.0)/k;
        double res=sum;
        for (int i=0;i<nums.size()-k;i++)
        {
            sum+=(double)(nums[k+i]-nums[i])/k;
            res=res<sum?sum:res;
        }
        return res;
    }
};