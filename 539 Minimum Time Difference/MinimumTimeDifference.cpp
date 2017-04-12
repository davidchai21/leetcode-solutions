class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        if (n<2) return 0;
        sort(timePoints.begin(),timePoints.end());
        int res=diff(timePoints[0],timePoints[n-1]);
        for (int i=0;i<n-1;i++)
        {
            res=min(res,diff(timePoints[i],timePoints[i+1]));
        }
        return res;
    }
private:
    inline int diff(string a, string b)
    {
        if (a==b) return 0;
        int ha=(a[0]-'0')*10+a[1]-'0';
        int hb=(b[0]-'0')*10+b[1]-'0';
        int ma=(a[3]-'0')*10+a[4]-'0';
        int mb=(b[3]-'0')*10+b[4]-'0';
        int x=((ha-hb)*60+ma-mb<0)?((ha-hb+24)*60+ma-mb):((ha-hb)*60+ma-mb);
        return x>720?1440-x:x;
    }
};