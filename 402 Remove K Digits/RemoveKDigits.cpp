class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k>=num.size()) return "0";
        string res=num;
        int i=0;
        while (k)
        {
            for (i=0;i<res.size()-1;i++)
            {
                if (res[i]>res[i+1])
                {
                    break;
                }
            }
            res.erase(res.begin()+i);
            k--;
        }
        for (i=0;i<res.size();i++)
        {
            if (res[i]!='0') break;
        }
        if (i==res.size()) return "0";
        else
        {
            res=res.substr(i,res.size()-i);
            return res;
        }
    }
};