class Solution {
public:
    int titleToNumber(string s) {
        int res=0;
        for (char a:s)
        {
            res=res*26+(a-'A'+1);
        }
        return res;
    }
};