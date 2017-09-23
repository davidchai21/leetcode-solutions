class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int left=arrays[0][0];
        int right=arrays[0][arrays[0].size()-1];
        int res=INT_MIN;
        for (int i=1;i<arrays.size();i++)
        {
            res=max(res,max(abs(left-arrays[i][arrays[i].size()-1]),abs(right-arrays[i][0])));
            left=min(left,arrays[i][0]);
            right=max(right,arrays[i][arrays[i].size()-1]);
        }
        return res;
    }
};