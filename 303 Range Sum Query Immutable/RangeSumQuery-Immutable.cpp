class NumArray {
public:
    NumArray(vector<int> nums) {
        a=nums;
        for (int i=1;i<nums.size();i++)
        {a[i]+=a[i-1];}
    }
    
    int sumRange(int i, int j) {
        return a[j]-a[i-1];
    }
private:
    vector<int> a;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */