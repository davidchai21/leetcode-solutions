class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val)!=m.end()) return false;
        s.push_back(val);
        m[val]=s.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val)==m.end()) return false;
        int last=s.back();
        m[last]=m[val];
        s[m[val]]=last;
        m.erase(val);
        s.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return s[rand()%s.size()];
    }
private:
    unordered_map<int,int> m;
    vector<int> s;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */