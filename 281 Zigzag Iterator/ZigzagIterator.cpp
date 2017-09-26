class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.size()) q.push(make_pair(v1.begin(),v1.end()));
        if (v2.size()) q.push(make_pair(v2.begin(),v2.end()));
    }

    int next() {
        vector<int>::iterator left=q.front().first;
        vector<int>::iterator right=q.front().second;
        q.pop();
        if (left+1!=right) q.push(make_pair(left+1,right));
        return *left;
    }

    bool hasNext() {
        return !q.empty();
    }
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator> > q;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */