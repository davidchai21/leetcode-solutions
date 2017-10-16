class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        unordered_map<char,int> m;
        bool flag=false;
        string mid="";
        string half="";
        for (char a:s) m[a]++;
        for (auto p:m) {
            if (p.second%2) {
                if (!flag) {
                    flag=true;
                    mid+=p.first;
                }
                else return res;
            }
            for (int i=0;i<p.second/2;i++) half+=p.first;
        }
        sort(half.begin(),half.end());
        helper(half,res,mid);
        return res;
    }
    void helper(string half, vector<string>& res, string mid) {
        do {
            string t=half;
            reverse(t.begin(),t.end());
            res.push_back(t+mid+half);
        } while (next_permutation(half.begin(),half.end()));
    }
};