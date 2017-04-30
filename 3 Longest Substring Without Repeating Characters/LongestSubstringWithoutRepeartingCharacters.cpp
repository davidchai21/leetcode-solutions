class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> res(256,-1);
        int ans=0, p=-1;
        for (int i=0;i<s.size();i++)
        {
            if (res[s[i]]>p) p=res[s[i]];
            res[s[i]]=i;
            ans=max(ans,i-p);
        }
        return ans;
    } 
};
