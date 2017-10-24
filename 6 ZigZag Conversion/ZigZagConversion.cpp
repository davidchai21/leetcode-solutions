class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows<2) return s;
        int k=numRows*2-2;
        string res="";
        for (int i=0;i<s.size();i+=k) res+=s[i];
        for (int i=1;i<numRows-1;i++) {
            for (int j=i;j<s.size();j+=k) {
                res+=s[j];
                if (j+k-2*i<s.size()) res+=s[j+k-2*i];
            }
        }
        for (int i=numRows-1;i<s.size();i+=k) res+=s[i];
        return res;
    }
};