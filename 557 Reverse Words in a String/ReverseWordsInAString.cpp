class Solution {
public:
    string reverseWords(string& s) {
        int i=0; int j=0;
        int n=s.size();
        while (i<n)
        {
            while (s[i]==' ' && i<n) i++;
            j=i+1;
            while (s[j]!=' ' && j<n) j++;
            reverse(s.begin()+i,s.begin()+j);
            i=j;
        }
        return s;
    }
};