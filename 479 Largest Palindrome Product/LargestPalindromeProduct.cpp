class Solution {
public:
    int largestPalindrome(int n) {
        if (n==1) return 9;
        int upper=pow(10,n)-1;
        int lower=pow(10,n-1);
        for (int i=upper;i>=lower;i--)
        {
            long t=buildPalindrome(i);
            for (long j=upper;j*j>=t;j--) {
                if (t%j==0 && t/j<=upper) return t%1337;
            }
        }
        return -1;
    }
    long buildPalindrome(int n) {
        string s=to_string(n);
        reverse(s.begin(),s.end());
        return stol(to_string(n)+s);
    }
};