class Solution {
public:
    bool checkValidString(string s) {
        int left=0;
        int right=0;
        for (int i=0;i<s.size();i++) {
            left+=s[i]=='('?1:-1;
            right+=s[i]!=')'?1:-1;
            if (right<0) break;
            left=max(left,0);
        }
        return left==0;
    }
};