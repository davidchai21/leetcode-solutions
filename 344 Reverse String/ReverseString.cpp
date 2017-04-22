class Solution {
public:
    string reverseString(string s) {
        string res=s;
        reverse(res.begin(),res.end());
        return res;
    }
};