class Solution {
public:
    int calculate(string s) {
        stack<int> num, op;
        int res=0;
        int sign=1;
        int n=0;
        for (char a:s)
        {
            if (isdigit(a))
            {
                n=n*10+a-'0';
            }
            else
            {
                res+=sign*n;
                n=0;
                if (a=='+') sign=1;
                else if (a=='-') sign=-1;
                else if (a=='(')
                {
                    num.push(res);
                    op.push(sign);
                    res=0;
                    sign=1;
                }
                else if (a==')' && !op.empty())
                {
                    res=op.top()*res+num.top();
                    op.pop(); num.pop();
                }
            }
        }
        res+=n*sign;
        return res;
    }
};