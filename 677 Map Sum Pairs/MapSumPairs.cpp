class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        m[key]=val;
    }
    
    int sum(string prefix) {
        int s=0;
        for (auto it=m.begin();it!=m.end();it++)
        {
            if (it->first.find(prefix)==0) s+=it->second;
        }
        return s;
    }
private:
    unordered_map<string,int> m;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */