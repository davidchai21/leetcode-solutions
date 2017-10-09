class Solution {
public:
    int lengthLongestPath(string input) {
        int res=0;
        if (input.empty()) return res;
        vector<int> path(200);
        int level=0;
        bool file=false;
        int i=0;
        while (i<input.size()) {
            while (input[i]=='\t') {
                level++;
                i++;
            }
            int j=i+1;
            while (j<input.size() && input[j]!='\n') {
                if (input[j]=='.') file=true;
                j++;
            }
            if (!file) {
                if (level==0) path[0]=j-i+1;
                else path[level]=path[level-1]+j-i+1;
            }
            else {
                int l=path[level-1]+j-i;
                res=max(res,l);
            }
            level=0;
            i=j+1;
            file=false;
        }
        return res;
    }
};