class Solution {
public:
    string convertToBase7(int num) {
        string res;
        int a=abs(num);
        while (a)
        {
            res=to_string(a%7)+res;
            a/=7;
        }
        if (num<0) {res="-"+res;}
        return res;
    }
};