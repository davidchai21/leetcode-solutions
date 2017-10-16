class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if (k<=0 || sum%k) return false;
        int value=sum/k;
        vector<bool> visited(nums.size(),false);
        return helper(nums,visited,0,0,value,k);
    }
    bool helper(vector<int> nums, vector<bool>& visited, int start, int cur_sum, int value, int k) {
        if (k==1) return true;
        if (cur_sum==value) return helper(nums,visited,0,0,value,k-1);
        for (int i=start;i<visited.size();i++) {
            if (!visited[i]) {
                visited[i]=true;
                if (helper(nums,visited,i+1,cur_sum+nums[i],value,k)) return true;
                visited[i]=false;
            }
        }
        return false;
    }
};