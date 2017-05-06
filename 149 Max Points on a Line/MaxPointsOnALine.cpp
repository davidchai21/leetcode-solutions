/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size()<3) return points.size();
        int n=points.size();
        int res=0;
        for (int i=0;i<n-1;i++)
        {
            unordered_map<string,int> t;
            int duplicate=1;
            for (int j=i+1;j<n;j++)
            {
                if (points[j].x==points[i].x)
                {
                    if (points[j].y==points[i].y) {duplicate++;}
                    else {t["amelia"]++;}
                }
                else
                {
                    int a=points[j].y-points[i].y;
                    int b=points[j].x-points[i].x;
                    int g=gcd(a,b);
                    string l=to_string(a/g)+"/"+to_string(b/g);
                    t[l]++;
                }
            }
            int d=0;
            for (auto p:t)
            {d=max(d,p.second);}
            res=max(res,d+duplicate);
        }
        return res;
    }
private:
    int gcd(int a, int b)
    {
        return (a%b==0)?b:gcd(b,a%b);
    }
};