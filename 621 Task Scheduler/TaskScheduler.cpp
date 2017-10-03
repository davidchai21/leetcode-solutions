class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n==0) return tasks.size();
        unordered_map<char,int> m;
        int count=0;
        for (int i=0;i<tasks.size();i++) {
            m[tasks[i]]++;
            count=max(count,m[tasks[i]]);
        }
        int res=(n+1)*(count-1);
        for (auto a:m) {
            if (a.second==count) res++;
        }
        return max(res,(int)tasks.size());
    }
};