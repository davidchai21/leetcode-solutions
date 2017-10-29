class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n=org.size();
        if (n==0 || seqs.size()==0) return false;
        unordered_map<int,unordered_set<int> > m;
        vector<int> indegree(n+1,0);
        int count=0;
        for (auto seq:seqs) {
            for (int i=seq.size()-1;i>=0;i--) {
                if (seq[i]<=0 || seq[i]>n) return false;
                if (i>0 && m[seq[i]].find(seq[i-1])==m[seq[i]].end()) {
                    m[seq[i]].insert(seq[i-1]);
                    if (indegree[seq[i-1]]++==0) count++;
                }
                if (i==0 && m.find(seq[i])==m.end()) {
                    m.insert({seq[i],unordered_set<int>()});
                }
            }
        }
        if (count!=n-1 || m.size()!=n) return false;
        for (int i=n-1;i>0;i--) {
            if (indegree[org[i]]>0) return false;
            for (auto p:m[org[i]]) {
                indegree[p]--;
                if (indegree[p]==0 && p!=org[i-1]) return false;
            }
        }
        return true;
    }
};