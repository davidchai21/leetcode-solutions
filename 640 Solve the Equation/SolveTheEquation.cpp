class Solution {
public:
    string solveEquation(string equation) {
        int k=0;
        while (equation[k]!='=') k++;
        pair<int,int> left=partition(equation.substr(0,k));
        pair<int,int> right=partition(equation.substr(k+1));
        int x=left.first-right.first;
        int y=-left.second+right.second;
        if (x==0) {
            if (y==0) return "Infinite solutions";
            else return "No solution";
        }
        else return "x="+to_string(y/x);
    }
    pair<int,int> partition(string s) {
        int left=0;
        int right=0;
        int n=s.size();
        if (n==0) return {0,0};
        int i=0;
        while (i<n) {
            int j=i+1;
            while (j<n && (s[j]!='+' && s[j]!='-')) j++;
            string a=s.substr(i,j-i);
            i=j;
            if (a.back()!='x') right+=stoi(a);
            else {
                if (a=="x" || a=="+x") left+=1;
                else if (a=="-x") left-=1;
                else {
                    a.pop_back();
                    left+=stoi(a);
                }
            }
        }
        return make_pair(left,right);
    }
};