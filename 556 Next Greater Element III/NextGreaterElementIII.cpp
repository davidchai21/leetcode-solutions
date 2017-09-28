class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int i=s.size()-1;
        while (i>0 && s[i]<=s[i-1]) i--;
        if (i==0) return -1;
        int j=i;
        int index=j;
        while (j<s.size()) {
            if (s[j]<s[index] && s[j]>s[i-1]) index=j;
            j++;
        }
        swap(s[i-1],s[index]);
        sort(s.begin()+i,s.end());
        long t=stol(s);
        return t>INT_MAX?-1:t;
    }
};