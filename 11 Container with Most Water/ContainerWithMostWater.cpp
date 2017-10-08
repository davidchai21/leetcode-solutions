class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        if (n<2) return 0;
        int i=0;
        int j=n-1;
        int res=min(height[i],height[j])*(j-i);
        int left=height[i];
        int right=height[j];
        while (i<j) {
            if (left<right) {
                while (i<j && height[i]<=left) i++;
                left=height[i];
            }
            else {
                while (i<j && height[j]<=right) j--;
                right=height[j];
            }
            res=max(res,min(height[i],height[j])*(j-i));
        }
        return res;
    }
};