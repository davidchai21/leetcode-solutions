class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        if (n==0) return true;
        int i=0,j=n-1;
        while (i<j)
        {
            while (!isLetter(s[i]) && i<n) i++;
            while (!isLetter(s[j]) && j>=0) j--;
            if (tolower(s[i])!=tolower(s[j])) return false;
            else
            {
                i++; j--;
            }
        }
        return true;
    }
private:
    bool isLetter(char a)
    {
        if ((a>='a' && a<='z') || (a>='A' && a<='Z') || (a>='0' && a<='9')) return true;
        else return false;
    }
};