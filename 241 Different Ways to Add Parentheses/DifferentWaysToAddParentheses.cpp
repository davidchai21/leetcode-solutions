class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i=0;i<input.size();i++) {
            if (input[i]=='+' || input[i]=='-' || input[i]=='*') {
                vector<int> left=diffWaysToCompute(input.substr(0,i));
                vector<int> right=diffWaysToCompute(input.substr(i+1));
                for (int a:left) {
                    for (int b:right) {
                        if (input[i]=='+') res.push_back(a+b);
                        else if (input[i]=='-') res.push_back(a-b);
                        else if (input[i]=='*') res.push_back(a*b);
                    }
                }
            }
        }
        if (res.empty()) res.push_back(stoi(input));
        return res;
    }
};