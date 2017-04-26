class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int t=0;
        for (int i=0;i<machines.size();i++) {t+=machines[i];}
        if (t%machines.size()) return -1;
        int a=t/machines.size();
        int c=0;
        int res=0;
        for (int i=0;i<machines.size();i++)
        {
            c+=machines[i]-a;
            res=max(max(res,machines[i]-a),abs(c));
        }
        return res;
    }
};