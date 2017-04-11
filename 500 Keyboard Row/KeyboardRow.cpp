class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> a{'q','Q','w','W','e','E','R','r','t','T','Y','y','U','u','i','I','o','O','p','P'};
        unordered_set<char> b{'a','s','d','f','g','h','j','k','l','A','S','D','F','G','H','J','K','L'};
        unordered_set<char> c{'Z','X','C','V','B','N','M','z','x','c','v','b','n','m'};
        vector<unordered_set<char> > s{a,b,c};
        
        vector<string> res;
        int l=-1;
        for (int i=0;i<words.size();i++)
        {
            for (int j=0;j<3;j++)
            {
                bool flag=false;
                if (s[j].find(words[i][0])!=s[j].end())
                {
                    flag=true;
                    for (int m=1;m<words[i].size();m++)
                    {
                        if (s[j].find(words[i][m])==s[j].end())
                        {
                            flag=false;
                            break;
                        }
                    }
                }
                if (flag)
                {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};