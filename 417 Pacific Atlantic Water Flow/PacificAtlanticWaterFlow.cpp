class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int,int> > res;
        int m=matrix.size();
        if (m==0) return res;
        int n=matrix[0].size();
        if (n==0) return res;
        queue<pair<int,int> > a,b;
        vector<vector<pair<bool,bool> > > flow(m,vector<pair<bool,bool> >(n,pair<bool,bool>(false,false)));
        for (int i=0;i<m;i++) {
            a.push({i,0});
            b.push({i,n-1});
            flow[i][0].first=true;
            flow[i][n-1].second=true;
        }
        for (int i=0;i<n;i++) {
            a.push({0,i});
            b.push({m-1,i});
            flow[0][i].first=true;
            flow[m-1][i].second=true;
        }
        pacific(matrix,flow,a,m,n);
        atlantic(matrix,flow,b,m,n);
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (flow[i][j].first && flow[i][j].second) res.push_back({i,j});
            }
        }
        return res;
    }
    void pacific(vector<vector<int> > matrix, vector<vector<pair<bool,bool> > >& flow, queue<pair<int,int> >& a, int m, int n) {
        while (!a.empty()) {
            int x=a.front().first;
            int y=a.front().second;
            a.pop();
            for (int i=0;i<4;i++) {
                int l=dir[i].first+x;
                int r=dir[i].second+y;
                if (l>=0 && l<m && r>=0 && r<n) {
                    if (flow[l][r].first==false && matrix[l][r]>=matrix[x][y]) {
                        flow[l][r].first=true;
                        a.push({l,r});
                    }
                }
            }
        }
    }
    void atlantic(vector<vector<int> > matrix, vector<vector<pair<bool,bool> > >& flow, queue<pair<int,int> >& a, int m, int n) {
        while (!a.empty()) {
            int x=a.front().first;
            int y=a.front().second;
            a.pop();
            for (int i=0;i<4;i++) {
                int l=dir[i].first+x;
                int r=dir[i].second+y;
                if (l>=0 && l<m && r>=0 && r<n) {
                    if (flow[l][r].second==false && matrix[l][r]>=matrix[x][y]) {
                        flow[l][r].second=true;
                        a.push({l,r});
                    }
                }
            }
        }
    }
private:
    vector<pair<int,int> > dir={{0,1},{0,-1},{1,0},{-1,0}};
};