class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        if (n<2) return;
        nth_element(nums.begin(),nums.begin()+n/2,nums.end());
        int mid=nums[n/2];
        #define A(i) nums[(1+2*i)%(n|1)] // index-rewiring
        int i=0;
        int j=0;
        int k=n-1;
        while (j<=k) {
            if (A(j)<mid) {
                swap(A(j),A(k--));
            }
            else if (A(j)>mid) {
                swap(A(j++),A(i++));
            }
            else j++;
        }
    }
};