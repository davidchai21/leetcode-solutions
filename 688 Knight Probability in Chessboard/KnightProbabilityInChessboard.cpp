class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<pair<int,int> > dir={{1,2},{2,1},{-1,2},{-2,1},{1,-2},{2,-1},{-1,-2},{-2,-1}};
        vector<vector<vector<double> > > res(K+1,vector<vector<double> >(N,vector<double>(N,-1)));
        return helper(res,N,K,r,c,dir)/pow(8,K);
    }
    double helper(vector<vector<vector<double> > >& res, int N, int k, int r, int c, vector<pair<int,int> > dir) {
        if (r<0 || r>=N || c<0 || c>=N) return 0.0;
        if (k==0) return 1.0;
        if (res[k][r][c]!=-1) return res[k][r][c];
        res[k][r][c]=0.0;
        for (int l=0;l<8;l++) {
            int x=r+dir[l].first;
            int y=c+dir[l].second;
            res[k][r][c]+=helper(res,N,k-1,x,y,dir);
        }
        return res[k][r][c];
    }
};