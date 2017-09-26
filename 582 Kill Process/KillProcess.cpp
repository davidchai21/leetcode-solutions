class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> res;
        unordered_map<int,vector<int> > m;
        for (int i=0;i<pid.size();i++) m[ppid[i]].push_back(pid[i]);
        queue<int> q;
        q.push(kill);
        res.push_back(kill);
        while (!q.empty()) {
            int t=q.front();
            q.pop();
            if (m.find(t)!=m.end()) {
                for (int i=0;i<m[t].size();i++)
                {
                    q.push(m[t][i]);
                    res.push_back(m[t][i]);
                }
            }
        }
        return res;
    }
};