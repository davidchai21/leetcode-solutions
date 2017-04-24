class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        stack<int> s;
        heights.push_back(0);
        int res=0;
        for (int i=0;i<heights.size();i++)
        {
            if (s.empty() || heights[i]>=heights[s.top()]) s.push(i);
            else
            {
                int t=heights[s.top()];
                s.pop();
                res=max(res,t*(s.empty()?i:i-1-s.top()));
                i--;
            }
        }
        return res;
    }
};