class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int> count(26,0);
        int start=0;
        int maxl=0;
        int res=0;
        for (int i=0;i<n;i++) {
            count[s[i]-'A']++;
            if (count[s[i]-'A']>maxl) maxl=count[s[i]-'A'];
            while (i-start-maxl+1>k) {
                count[s[start]-'A']--;
                start++;
                for (int j=0;j<26;j++) {
                    if (maxl<count[j]) maxl=count[j];
                }
            }
            res=max(res,i-start+1);
        }
        return res;
    }
};