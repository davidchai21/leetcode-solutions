class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string t=A;
        for (int res=1;res<=B.size()/A.size()+2;res++) {
            if (t.find(B)!=string::npos) return res;
            t+=A;
        }
        return -1;
    }
};