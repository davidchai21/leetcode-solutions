class Solution {
public:
    Solution(vector<int> nums) {
        n=nums;
    }
    
    int pick(int target) {
        int index=-1;
        int count=1;
        for (int i=0;i<n.size();i++) {
            if (n[i]==target) {
                int r=rand()%count++;
                if (r==0) index=i;
            }
        }
        return index;
    }
private:
    vector<int> n;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */