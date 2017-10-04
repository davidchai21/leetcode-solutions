class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        it=vec2d.begin();
        e1=vec2d.end();
        i=0;
    }

    int next() {
        return (*it)[i++];
    }

    bool hasNext() {
        while (it!=e1 && i==it->size()) {
            it++;
            i=0;
        }
        return it!=e1 && i<it->size();
    }
private:
    vector<vector<int> >::iterator it;
    vector<vector<int> >::iterator e1;
    int i;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */