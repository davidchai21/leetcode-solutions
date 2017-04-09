class Solution {
public:
    string reverseStr(string s, int k) {
        string res=s;
        int n=s.size();
        int i=0;
        while (i+2*k<=n)
        {
            reverse(res.begin()+i,res.begin()+i+k);
            i+=2*k;
        }
        if (i<n)
        {
            if (i+k<=n)
            {
                reverse(res.begin()+i,res.begin()+i+k);
            }
            else
            {
                reverse(res.begin()+i,res.end());
            }
        }
        return res;
    }
};