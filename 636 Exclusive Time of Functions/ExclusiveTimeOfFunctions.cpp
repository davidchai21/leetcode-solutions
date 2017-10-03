class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n,0);
        stack<pair<int,int> > s;
        for (int i=0;i<logs.size();i++) {
            Line t=parse(logs[i]);
            if (t.start) {
                s.push(make_pair(t.id,t.t));
            }
            else {
                pair<int,int> st=s.top();
                s.pop();
                res[st.first]+=t.t-st.second+1;
                if (!s.empty()) {
                    res[s.top().first]-=t.t-st.second+1;
                }
            }
        }
        return res;
    }
    struct Line {
        int id;
        bool start;
        int t;
        Line(int a, bool b, int c):id(a), start(b), t(c) {}
    };
    Line parse(string a) {
        int x=a.find(':',0);
        int y=a.find(':',x+1);
        string id=a.substr(0,x);
        string start=a.substr(x+1,y-x-1);
        string t=a.substr(y+1);
        return Line(stoi(id),start=="start",stoi(t));
    }
};