class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, bool> m;
        for (char a:J) {
            m[a]=true;
        }
        int res=0;
        for (char a:S) {
            if (m[a]) res++;
        }
        return res;
    }
};