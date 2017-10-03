class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m=maze.size();
        if (!m) return false;
        int n=maze[0].size();
        if (!n) return false;
        vector<vector<bool> > visited(m,vector<bool>(n,false));
        queue<pair<int,int> > q;
        q.push(make_pair(start[0],start[1]));
        visited[start[0]][start[1]]=true;
        while (!q.empty()) {
            pair<int,int> cur=q.front();
            if (helper(maze,cur,m,n,visited,q,destination)) return true;
            q.pop();
        }
        return false;
    }
    bool helper(vector<vector<int> > maze, pair<int,int> a, int m, int n, vector<vector<bool> >& v, queue<pair<int,int> >& q, vector<int> d) {
        int i=a.first;
        int j=a.second;
        while (i>=0 && maze[i][j]==0) i--;
        i++;
        if (d[0]==i && d[1]==j) return true;
        if (v[i][j]==false) {
            v[i][j]=true;
            q.push(make_pair(i,j));
        }
        i=a.first;
        j=a.second;
        while (i<m && maze[i][j]==0) i++;
        i--;
        if (d[0]==i && d[1]==j) return true;
        if (v[i][j]==false) {
            v[i][j]=true;
            q.push(make_pair(i,j));
        }
        i=a.first;
        j=a.second;
        while (j<n && maze[i][j]==0) j++;
        j--;
        if (d[0]==i && d[1]==j) return true;
        if (v[i][j]==false) {
            v[i][j]=true;
            q.push(make_pair(i,j));
        }
        i=a.first;
        j=a.second;
        while (j>=0 && maze[i][j]==0) j--;
        j++;
        if (d[0]==i && d[1]==j) return true;
        if (v[i][j]==false) {
            v[i][j]=true;
            q.push(make_pair(i,j));
        }
        return false;
    }
};