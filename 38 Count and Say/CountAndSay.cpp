class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        for (int i=1;i<n;i++)
        {
            res=helper(res);
        }
        return res;
    }
    string helper(string& s)
    {
        int count=0;
        char cur=s[0];
        string res="";
        for (int i=0;i<s.size();i++)
        {
            if (s[i]==cur) {
                count++;
            }
            else {
                res+=to_string(count)+cur;
                cur=s[i];
                count=1;
            }
        }
        res+=to_string(count)+cur;
        return res;
    }
};