class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        l=longUrl;
        return s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        s=shortUrl;
        return l;
    }
private:
    string s;
    string l;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));