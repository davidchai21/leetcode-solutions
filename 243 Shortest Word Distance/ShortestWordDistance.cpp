class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int one=-1;
        int two=-1;
        int res=INT_MAX;
        for (int i=0;i<words.size();i++)
        {
            if (words[i]==word1) one=i;
            else if (words[i]==word2) two=i;
            else continue;
            if (one!=-1 && two!=-1)
            {
                res=min(res,abs(one-two));
            }
        }
        return res;
    }
};