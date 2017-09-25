class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        int n=paths.size();
        vector<vector<string> > res;
        unordered_map<string,vector<string> > m;
        for (int i=0;i<n;i++) {
            stringstream ss(paths[i]);
            string path, content;
            ss>>path;
            while (ss>>content) {
                int i=content.find('(');
                int j=content.find(')');
                string filename=content.substr(0,i);
                string inside=content.substr(i+1,j-i-1);
                m[inside].push_back(path+"/"+filename);
            }
        }
        for (auto a:m) {
            if (a.second.size()>1) {
                res.push_back(a.second);
            }
        }
        return res;
    }
};