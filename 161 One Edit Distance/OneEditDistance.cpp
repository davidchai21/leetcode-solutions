class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m=s.size();
        int n=t.size();
        if (abs(m-n)>1) return false;
        if (m>n) return isOneEditDistance(t,s);
        bool flag=false;
        int i=0;
        for (;i<m;i++) {
            if (s[i]!=t[i]) {
                if (m==n) s[i]=t[i];
                else s.insert(i,1,t[i]);
                flag=true;
                break;
            }
        }
        if (!flag) return m+1==n;
        else return s==t;
    }
};