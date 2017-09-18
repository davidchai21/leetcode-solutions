class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        int n=s.size();
        if (n<2) return res;
        for (int i=0;i<n-1;i++)
        {
            if (s[i]==s[i+1] && s[i]=='+') {
                string left(s.begin(),s.begin()+i);
                string right(s.begin()+i+2,s.end());
                res.push_back(left+"--"+right);
            }
        }
        return res;
    }
};