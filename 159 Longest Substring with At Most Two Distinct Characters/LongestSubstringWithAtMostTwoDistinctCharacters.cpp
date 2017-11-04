class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        char a=0;
        char b=0;
        int count1=0;
        int count2=0;
        int start=0;
        int res=0;
        for (int i=0;i<s.size();i++) {
            if (s[i]!=a && s[i]!=b) {
                while (count1 && count2) {
                    if (s[start]==a) count1--;
                    else count2--;
                    start++;
                }
                if (count1==0) {
                    a=s[i];
                    count1=1;
                }
                else {
                    b=s[i];
                    count2=1;
                }
            }
            else {
                if (s[i]==a) count1++;
                else count2++;
            }
            res=max(count1+count2,res);
        }
        return res;
    }
};