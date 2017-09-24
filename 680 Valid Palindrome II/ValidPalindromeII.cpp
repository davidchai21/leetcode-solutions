class Solution {
public:
    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while (i<j) {
            if (s[i]==s[j]) {i++;j--;}
            else return helper(s,i+1,j) || helper(s,i,j-1);
        }
        return true;
    }
    bool helper(string s, int i, int j)
    {
        while (i<j)
        {
            if (s[i++]!=s[j--]) return false;
        }
        return true;
    }
};