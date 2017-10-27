class Solution {
public:
    string validIPAddress(string IP) {
        int i;
        for (i=0;i<IP.size();i++) {
            if (!isdigit(IP[i]) && !isalpha(IP[i])) break;
        }
        char delim=IP[i];
        if (delim=='.' && IP4(IP+".")) return "IPv4";
        else if (delim==':' && IP6(IP+":")) return "IPv6";
        else return "Neither";
    }
    bool IP6(string s) {
        istringstream ss(s);
        string t;
        int n=8;
        while (n && getline(ss,t,':')) {
            if (t.size()>4 || t.empty()) return false;
            for (int i=0;i<t.size();i++) {
                if (!isdigit(t[i]) && (!isalpha(t[i]) || tolower(t[i])>'f')) return false;
            }
            n--;
        }
        return n==0 && !getline(ss,t,':');
    }
    bool IP4(string s) {
        int n=4;
        int i=0;
        while (n && i<s.size()) {
            int j=i;
            while (j<s.size() && isdigit(s[j])) j++;
            if (s[j]!='.') return false;
            if (i==j || j-i>3 || s[i]=='0' && j>i+1) return false;
            int p=stoi(s.substr(i,j-i));
            if (p<0 || p>255) return false;
            i=j+1;
            n--;
        } 
        return i>=s.size() && n==0;
    }
};