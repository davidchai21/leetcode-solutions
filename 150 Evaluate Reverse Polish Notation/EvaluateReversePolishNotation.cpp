class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;
        stack<int> s;
        for (string p:tokens) {
            if (p=="+" || p=="-" || p=="*" || p=="/") {
                int a=s.top();
                s.pop();
                if (p=="+") s.top()+=a;
                else if (p=="-") s.top()-=a;
                else if (p=="*") s.top()*=a;
                else if (p=="/") s.top()/=a; 
            }
            else s.push(stoi(p));
        }
        return s.top();
    }
};