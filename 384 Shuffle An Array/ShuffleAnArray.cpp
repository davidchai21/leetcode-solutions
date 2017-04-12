class Solution {
public:
    Solution(vector<int> nums) {
        a=nums;
        index=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return index;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int i=a.size();
        while (i)
        {
            int j=rand()%i;
            swap(a[j], a[--i]);
        }
        return a;
    }
private:
    vector<int> a,index;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */