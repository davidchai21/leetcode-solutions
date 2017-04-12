class Solution {
public:
    string decodeString(string s) {
        int a=0;
        return helper(s,a);
    }
private:
    string helper(string& a, int& i)
    {
        string res="";
        while (i<a.size() && a[i]!=']')
        {
            if (!isdigit(a[i])) res+=a[i++];
            else
            {
                int n=0;
                while (isdigit(a[i]))
                {
                    n=10*n+a[i++]-'0';
                }
                i++;
                string t=helper(a,i);
                i++;
                while (n-->0) res+=t;
            }
        }
        return res;
    }
};