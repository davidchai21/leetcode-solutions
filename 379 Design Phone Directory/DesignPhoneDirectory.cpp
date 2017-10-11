class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        can.resize(maxNumbers,0);
        used.resize(maxNumbers,false);
        for (int i=1;i<maxNumbers;i++) can[i]=i;
        index=0;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (index>=can.size()) return -1;
        used[can[index]]=true;
        int t=can[index++];
        return t;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return !used[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (used[number]) {
            used[number]=false;
            can[--index]=number;
        }
    }
private:
    vector<int> can;
    vector<bool> used;
    int index=0;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */