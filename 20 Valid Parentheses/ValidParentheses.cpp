class Solution {
public:
    bool isValid(string s) {
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='(' || s[i]=='[' || s[i]=='{') a.push(s[i]);
            else
            {
                if (!a.empty()){
                    if (s[i]==']' && a.top()=='[') a.pop();
                    else if (s[i]==')' && a.top()=='(') a.pop();
                    else if (s[i]=='}' && a.top()=='{') a.pop();
                    else return false;
                }
                else return false;
            }
        }
        return a.empty();
    }
private:
    stack<char> a;
};