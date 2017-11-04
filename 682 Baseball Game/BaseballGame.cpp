class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res=0;
        stack<int> s;
        for (int i=0;i<ops.size();i++) {
            if (ops[i]=="+") {
                int t=s.top();
                s.pop();
                int t2=s.top();
                s.push(t);
                s.push(t+t2);
                res+=s.top();
            }
            else if (ops[i]=="D") {
                s.push(2*s.top());
                res+=s.top();
            }
            else if (ops[i]=="C") {
                res-=s.top();
                s.pop();
            }
            else {
                s.push(stoi(ops[i]));
                res+=s.top();
            }
        }
        return res;
    }
};