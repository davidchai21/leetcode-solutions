/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        unordered_map<int,UndirectedGraphNode*> m;
        unordered_map<int,vector<int> > n;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        while (!q.empty()) {
            UndirectedGraphNode* t=q.front();
            q.pop();
            if (m.find(t->label)==m.end()) {
                m[t->label]=new UndirectedGraphNode(t->label);
                for (int i=0;i<t->neighbors.size();i++) {
                    q.push(t->neighbors[i]);
                    n[t->label].push_back(t->neighbors[i]->label);
                }
            }
        }
        for (auto p:n) {
            for (int i=0;i<p.second.size();i++) {
                m[p.first]->neighbors.push_back(m[p.second[i]]);
            }
        }
        return m[node->label];
    }
};