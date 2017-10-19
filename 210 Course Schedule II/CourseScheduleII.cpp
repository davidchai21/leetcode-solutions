class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<vector<int> > graph(numCourses,vector<int>());
        for (int i=0;i<prerequisites.size();i++) {
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        vector<int> indegree(numCourses,0);
        for (int i=0;i<graph.size();i++) {
            for (int j=0;j<graph[i].size();j++) {
                indegree[graph[i][j]]++;
            }
        }
        for (int i=0;i<numCourses;i++) {
            int j=0;
            for (;j<numCourses;j++) {
                if (indegree[j]==0) break;
            }
            if (j==numCourses) return vector<int>();
            res.push_back(j);
            indegree[j]=-1;
            for (int k=0;k<graph[j].size();k++) {
                indegree[graph[j][k]]--;
            }
        }
        return res;
    }
};