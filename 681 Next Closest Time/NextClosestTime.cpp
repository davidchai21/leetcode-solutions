class Solution {
public:
    string nextClosestTime(string time) {
        vector<int> v;
        for (int i=0;i<time.size();i++) {
            if (time[i]!=':') {
                int t=time[i]-'0';
                int j=0;
                for (;j<v.size();j++) {
                    if (t==v[j]) break;
                }
                if (j==v.size()) v.push_back(t);
            }
        }
        sort(v.begin(),v.end());
        vector<string> res;
        helper(res,v);
        int a=0;
        for (;a<res.size();a++) {
            if (res[a]==time) break;
        }
        if (a==res.size()-1) return res[0];
        else return res[a+1];
    }
    bool valid(string a){
        return ((a[0]-'0')*10+a[1]-'0')<24 && ((a[3]-'0')*10+a[4]-'0')<60;
    }
    void helper(vector<string>& res, vector<int> v) {
        int n=v.size();
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                for (int k=0;k<n;k++) {
                    for (int l=0;l<n;l++) {
                        string t=to_string(v[i])+to_string(v[j])+":"+to_string(v[k])+to_string(v[l]);
                        if (valid(t)) res.push_back(t);
                    }
                }
            }
        }
    }
};