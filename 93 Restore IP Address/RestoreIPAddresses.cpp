class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        for (int a=1;a<=3;a++) {
            for (int b=1;b<=3;b++) {
                for (int c=1;c<=3;c++) {
                    for (int d=1;d<=3;d++) {
                        if (a+b+c+d==s.size()) {
                            int e=stoi(s.substr(0,a));
                            int f=stoi(s.substr(a,b));
                            int g=stoi(s.substr(a+b,c));
                            int h=stoi(s.substr(a+b+c));
                            if (e>=0 && e<256 && f>=0 && f<256 && g>=0 && g<256 && h>=0 && h<256) {
                                string t=to_string(e)+"."+to_string(f)+"."+to_string(g)+"."+to_string(h);
                                if (t.size()==s.size()+3) res.push_back(t);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};