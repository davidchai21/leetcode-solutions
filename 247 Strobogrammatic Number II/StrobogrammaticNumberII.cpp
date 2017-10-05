class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        if (n<=0) return res;
        string s="";
        helper(n,s,res);
        return res;
    }
    void helper(int n, string& s, vector<string>& res) {
        if (s.size()==n/2) {
            implement(s,n,res);
            return;
        }
        for (int i=0;i<5;i++) {
            s.push_back(table[i]);
            if (s.empty() || s[0]!='0') helper(n,s,res);
            s.pop_back();
        }
    }
    void implement(string s, int n, vector<string>& res) {
        string t="";
        for (int i=s.size()-1;i>=0;i--) {
            if (s[i]=='6') t+='9';
            else if (s[i]=='9') t+='6';
            else t+=s[i];
        }
        if (n%2) {
            res.push_back(s+"0"+t);
            res.push_back(s+"1"+t);
            res.push_back(s+"8"+t);
        }
        else res.push_back(s+t);
    }
private:
    const char table[5]={'0','1','6','8','9'};
};