class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        if (n<3) return false;
        vector<int> s(nums.size(),nums[0]);
        int m=nums[0];
        for (int i=1;i<n;i++) {
            if (nums[i]<m) m=nums[i];
            s[i]=m;
        }
        stack<int> st;
        st.push(nums[n-1]);
        for (int i=n-2;i>0;i--) {
            if (st.empty() || st.top()>=nums[i]) st.push(nums[i]);
            else {
                while (!st.empty() && st.top()<nums[i]) {
                    if (st.top()>s[i]) return true;
                    st.pop();
                }
                st.push(nums[i]);
            }
        }
        return false;
    }
};