class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        long pre=0;
        long cur;
        int n=points.size();
        for (int i=0;i<n;i++) {
            if (cur=helper(points[i],points[(i+1)%n],points[(i+2)%n])) {
                if (pre*cur<0) return false;
                pre=cur;
            }
        }
        return true;
    }
    long helper(vector<int> a, vector<int> b, vector<int> c) {
        return (b[0]-a[0])*(c[1]-b[1])-(c[0]-b[0])*(b[1]-a[1]);
    }
};