class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (ls.find(longUrl)!=ls.end()) return ls[longUrl];
        else {
            string t="";
            long n=id;
            id++;
            do {
                t=dict[n%62]+t;
                n/=62;
            } while (n);
            ls[longUrl]=t;
            sl[t]=longUrl;
            return t;
        }
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return sl[shortUrl];
    }
private:
    unordered_map<string,string> ls;
    unordered_map<string,string> sl;
    long id=0;
    string dict="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));