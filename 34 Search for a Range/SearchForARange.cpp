class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1,-1};
        int i=0;
        int j=nums.size()-1;
        vector<int> res(2,-1);
        while (i<j) {
            int mid=i+(j-i)/2;
            if (nums[mid]<target) i=mid+1;
            else j=mid;
        }
        if (nums[i]!=target) return res;
        res[0]=i;
        i=0;
        j=nums.size()-1;
        while (i<j) {
            int mid=i+(j-i)/2+1;
            if (nums[mid]>target) j=mid-1;
            else i=mid;
        }
        res[1]=j;
        return res;
    }
};