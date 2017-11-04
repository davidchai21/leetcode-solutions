/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,pair<int,vector<int> > > m;
        vector<int> s;
        for (int i=0;i<employees.size();i++) {
            m[employees[i]->id].first=employees[i]->importance;
            m[employees[i]->id].second=employees[i]->subordinates;
        }
        int res=0;
        queue<int> q;
        q.push(id);
        while (!q.empty()) {
            res+=m[q.front()].first;
            for (int i=0;i<m[q.front()].second.size();i++) {
                q.push(m[q.front()].second[i]);
            }
            q.pop();
        }
        return res;
    }
};