class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        pair<int,int> x=parse(a);
        pair<int,int> y=parse(b);
        return to_string(x.first*y.first-x.second*y.second)+"+"+to_string(x.first*y.second+x.second*y.first)+"i";
    }
    
    pair<int,int> parse(string s)
    {
        int a,b;
        int r=find(s.begin(),s.end(),'+')-s.begin();
        int c=find(s.begin(),s.end(),'i')-s.begin();
        a=stoi(s.substr(0,r));
        b=stoi(s.substr(r+1,c-r));
        return {a,b};
    }
};