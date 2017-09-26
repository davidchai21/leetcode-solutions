class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        unordered_map<string,vector<int> > m;
        for (int i=0;i<words.size();i++) {
            m[words[i]].push_back(i);
        }
        int res=INT_MAX;
        if (word1==word2) {
            for (int i=1;i<m[word1].size();i++)
            {
                if (res>m[word1][i]-m[word1][i-1]) res=m[word1][i]-m[word1][i-1];
            }
        }
        else {
            res=helper(m[word1],m[word2]);
        }
        return res;
    }
    int helper(vector<int> a,vector<int> b) {
        int i=0;
        int j=0;
        int res=INT_MAX;
        while (i<a.size() && j<b.size()) {
            if (a[i]<b[j]){
                res=min(res,b[j]-a[i]);
                if (i==a.size()-1) j++;
                else i++;
            }
            else {
                res=min(res,a[i]-b[j]);
                if (j==b.size()-1) i++;
                else j++;
            }
        }
        return res;
    }
};