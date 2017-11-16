class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        bool flag=false;
        string seg="";
        for (int i=0;i<source.size();i++) {
            for (int j=0;j<source[i].size();) {
                if (flag) {
                    if (j==source[i].size()-1) j++;
                    else {
                        if (source[i][j]=='*' && source[i][j+1]=='/') {
                            flag=false;
                            j+=2;
                        }
                        else j++;
                    }
                }
                else {
                    if (j==source[i].size()-1) seg+=source[i][j++];
                    else {
                        if (source[i][j]=='/') {
                            if (source[i][j+1]=='/') break;
                            else if (source[i][j+1]=='*') {
                                flag=true;
                                j+=2;
                            }
                            else seg+=source[i][j++];
                        }
                        else seg+=source[i][j++];
                    }
                }
            }
            if (!flag && !seg.empty()) {
                res.push_back(seg);
                seg="";
            }
        }
        return res;
    }
};