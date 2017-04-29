class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        if (n<2) return s;
        string t=s;
        reverse(t.begin(),t.end());
        if (t==s) return s;
        for (int i=1;i<n;i++)
        {
            if (t.substr(i,n-i)==s.substr(0,n-i)) return t.substr(0,i)+s;
        }
    }
};