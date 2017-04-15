class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag=false;
        int n=word.size();
        if (n==1) return true;
        int capital=0;
        int lower=0;
        if (word[0]>='A' && word[0]<='Z') flag=true;
        for (int i=1;i<n;i++)
        {
            if (word[i]>='a' && word[i]<='z') lower++;
            else capital++;
        }
        if ((flag && (lower==n-1 || capital==n-1)) || (!flag && lower==n-1)) return true;
        else return false;
    }
};