class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int n=equations.size();
        unordered_map<string, unordered_map<string,double> > m;
        vector<double> res(queries.size(),-1);
        if (n==0) return res;
        for (int i=0;i<n;i++) {
            m[equations[i].first][equations[i].second]=values[i];
            m[equations[i].second][equations[i].first]=1.0/values[i];
            m[equations[i].first][equations[i].first]=1.0;
            m[equations[i].second][equations[i].second]=1.0;
        }
        for (auto i=m.begin();i!=m.end();i++) {
            for (auto j=m.begin();j!=m.end();j++) {
                for (auto k=m.begin();k!=m.end();k++) {
                    j->second[k->first]=max(j->second[k->first], j->second[i->first]*i->second[k->first]);
                }
            }
        }
        for (int i=0;i<queries.size();i++) {
            double t=m[queries[i].first][queries[i].second];
            res[i]=t==0?-1:t;
        }
        return res;
    }
};