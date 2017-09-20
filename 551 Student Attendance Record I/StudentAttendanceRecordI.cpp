class Solution {
public:
    bool checkRecord(string s) {
        int a=0;
        int l=0;
        for (char c:s)
        {
            if (c=='A')
            {
                if (a) return false;
                a++;
                l=0;
            }
            else if (c=='L')
            {
                if (l>1) return false;
                l++;
            }
            else l=0;
        }
        return true;
    }
};