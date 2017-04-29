class Solution {
public:
    void reverseWords(string &s) {
        int k=0,m=s.size()-1;
        while (s[k]==' ') k++;
        while (s[m]==' ') m--;
        if (m<k) {s=""; return;}
        else s=s.substr(k,m+1-k);
        int n=s.size();
        if (n<2) return;
        reverse(s.begin(),s.end());
        int i=0;
        while (i<n)
        {
            while (s[i]==' ' && i<n) i++;
            int j=i+1;
            while (s[j]!=' ' && j<n) j++;
            reverse(s.begin()+i,s.begin()+j);
            i=j+1;
        }
        i=0;
        while (i<n)
        {
            while (s[i]!=' ' && i<n) i++;
            int j=i+1;
            while (s[j]==' ' && j<n) j++;
            if (j-i>1) s.erase(i+1,j-i-1);
            i=i+2;
        }
    }
};