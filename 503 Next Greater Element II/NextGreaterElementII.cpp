class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,-1);
        if (n==0) return res;
        stack<int> s;
        int i=0;
        while (i<n*2) {
            int t=nums[i%n];
            while (!s.empty() && nums[s.top()%n]<t) {
                res[s.top()%n]=t;
                s.pop();
            }
            s.push(i);
            i++;
        }
        return res;
    }
};