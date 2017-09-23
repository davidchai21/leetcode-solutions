class StringIterator {
public:
    StringIterator(string compressedString):s(compressedString), cur(0), f(0), i(0) {}
    
    char next() {
        if (f) {
            f--;
            return cur;
        }
        else if (i<s.size()) {
            int j=i+1;
            while (j<s.size() && isdigit(s[j])) j++;
            string t=s.substr(i+1,j-i-1);
            f=stoi(t)-1;
            cur=s[i];
            i=j;
            return cur;
        }
        else return ' ';
    }
    
    bool hasNext() {
        return i<s.size() || f>0;
    }
private:
    string s;
    char cur;
    int f;
    int i;//index
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */