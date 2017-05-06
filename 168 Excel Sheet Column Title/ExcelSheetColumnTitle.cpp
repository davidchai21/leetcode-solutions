class Solution {
public:
    string convertToTitle(int n) {
        string res="";
        while (n)
        {
            n--;
            char c=('A'+n%26);
            res=c+res;
            n/=26;
        }
        return res;
    }
};