class Solution {
public:
    int calculate(string s) {
        stack<int> num;
        stack<char> op;
        string n="";
        for (int i=0;i<s.size();i++) {
            if (s[i]==' ') continue;
            else if (isdigit(s[i])) {
                n+=s[i];
            }
            else {
                int t=stoi(n);
                n="";
                if (op.empty()) {
                    op.push(s[i]);
                    num.push(t);
                }
                else {
                    if (op.top()=='*') {
                        num.top()=num.top()*t;
                        op.pop();
                    }
                    else if (op.top()=='/') {
                        num.top()=num.top()/t;
                        op.pop();
                    }
                    else num.push(t);
                    op.push(s[i]);
                }
            }
        }
        int tail=stoi(n);
        if (!op.empty() && (op.top()=='*' || op.top()=='/')) {
            if (op.top()=='*') num.top()*=tail;
            else num.top()/=tail;
            op.pop();
        }
        else num.push(tail);
        tail=0;
        while (!op.empty()) {
            if (op.top()=='+') tail+=num.top();
            else if (op.top()=='-') tail-=num.top();
            num.pop();
            op.pop();
        }
        return tail+num.top();
    }
};