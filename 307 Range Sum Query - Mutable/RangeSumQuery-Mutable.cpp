class NumArray {
public:
    NumArray(vector<int> nums) {
        n=nums.size();
        int l=log2(n);
        if (pow(2,l)!=n) l++;
        n=pow(2,l);
        tree.resize(2*n,0);
        buildTree(nums);
    }
    
    void update(int i, int val) {
        update2(i,val);
    }
    
    int sumRange(int i, int j) {
        return getSum(i,j,0,n-1,1);
    }
private:
    int n;
    vector<int> tree;
    void buildTree(vector<int> nums) {
        for (int i=n;i>0;i>>=1) {
            for (int j=i-1;j>=0;j--) {
                if (i==n) tree[i+j]=j>=nums.size()?0:nums[j];
                else tree[i+j]=tree[2*(i+j)]+tree[2*(i+j)+1];
            }
        }
    }
    void update2(int index, int val) {
        int diff=val-tree[n+index];
        int k=n+index;
        while (k) {
            tree[k]+=diff;
            k>>=1;
        }
    }
    int getSum(int i, int j, int left, int right, int pos) {
        if (i<=left && j>=right) return tree[pos];
        if (i>right || j<left) return 0;
        int mid=left+(right-left)/2;
        return getSum(i,j,left,mid,pos*2)+getSum(i,j,mid+1,right,2*pos+1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */