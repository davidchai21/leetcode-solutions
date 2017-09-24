// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int t=-1;
        int res=0;
        while (1) {
            int t=min(read4(buf+res),n);
            res+=t;
            if (t<4) break;
            n-=4;
        }
        return res;
    }
};