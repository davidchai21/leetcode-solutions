class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        while (nums[i]==0) i++;
        while (nums[j]==2) j--;
        for (int k=i;k<=j;k++) {
            if (nums[k]==0) swap(nums[i++],nums[k]);
            else if (nums[k]==2) swap(nums[j--],nums[k--]);
        }
    }
};