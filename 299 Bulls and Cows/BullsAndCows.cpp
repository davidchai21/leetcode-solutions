class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> a,b;
        for (char x:secret) a[x]++;
        for (char y:guess) b[y]++;
        int cow=0;
        for (auto p=a.begin();p!=a.end();p++)
        {
            auto f=b.find(p->first);
            if (f!=b.end()) cow+=min(a[p->first],b[p->first]);
        }
        int bull=0;
        for (int i=0;i<secret.size();i++)
        {
            if (secret[i]==guess[i]) bull++;
        }
        return to_string(bull)+"A"+to_string(cow-bull)+"B";
    }
};