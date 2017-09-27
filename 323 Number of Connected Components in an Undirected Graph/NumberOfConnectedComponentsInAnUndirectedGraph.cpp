class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        group.resize(n);
        iota(group.begin(),group.end(),0);
        int c=0;
        for (auto e:edges) {
            if (!un(e.first,e.second)) c++;
        }
        return n-c;
    }
    int find(int i){
        while (i!=group[i]) {
            group[i]=group[group[i]];
            i=group[i];
        }
        return i;
    }
    bool un(int a, int b) {
        int x=find(a);
        int y=find(b);
        if (x!=y) {
            group[x]=y;
            return false;
        }
        return true;
    }
private:
    vector<int> group;
};