class Solution {
public:
    int countBinarySubstrings(string s) {
        int res=0;
        int j=0;
        char bit;
        for (int i=1;i<s.size();) {
            if (s[i]!=s[i-1]) {
                bit=s[i];
                j=i-1;
                while (j>=0 && i<s.size() && s[i]==bit && s[j]!=bit) {
                    i++;
                    j--;
                    res++;
                }
            }
            else i++;
        }
        return res;
    }
};