class Solution {
public:
    string parseTernary(string expression) {
        int n=expression.size()-1;
        stack<char> s;
        while (n>=0) {
            if (expression[n]=='?') {
                char a;
                if (expression[n-1]=='T') {
                    a=s.top();
                    s.pop();
                }
                else {
                    s.pop();
                    a=s.top();
                }
                s.pop();
                s.push(a);
                n-=2;
            }
            else if (expression[n]==':') n--;
            else s.push(expression[n--]);
        }
        string res="";
        res+=s.top();
        return res;
    }
};