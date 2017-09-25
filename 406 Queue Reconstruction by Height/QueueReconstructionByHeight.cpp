class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(),people.end(),[](pair<int,int> a, pair<int,int> b){return a.first>b.first || (a.first==b.first && a.second<b.second);});
        vector<pair<int,int> > res;
        for (auto a:people) {
            res.insert(a.second+res.begin(),a);
        }
        return res;
    }
};