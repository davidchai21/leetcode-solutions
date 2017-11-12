class Solution {
public:
    string countOfAtoms(string formula) {
        map<string,int> m;
        stack<pair<string,int> > s;
        string name="";
        int count=0;
        for (int i=0;i<formula.size();i++) {
            if (formula[i]=='(') {
                if (name!="") {
                    s.push(make_pair(name,count==0?1:count));
                    name="";
                    count=0;
                }
                s.push(make_pair("(",1));
            }
            else if (formula[i]==')') {
                if (name!="") {
                    s.push(make_pair(name,count==0?1:count));
                    name="";
                    count=0;
                }
                int j=i+1;
                while (j<formula.size() && isdigit(formula[j])) j++;
                int c=j==i+1?1:stoi(formula.substr(i+1,j-i-1));
                stack<pair<string,int> > t;
                while (s.top().first!="(") {
                    t.push(make_pair(s.top().first,s.top().second*c));
                    s.pop();
                }
                s.pop();
                while (!t.empty()) {
                    s.push(t.top());
                    t.pop();
                }
                i=j-1;
            }
            else {
                if (isupper(formula[i])) {
                    if (name!="") {
                        if (count==0) s.push(make_pair(name,1));
                        else s.push(make_pair(name,count));
                        name="";
                        count=0;
                    }
                    name+=formula[i];
                }
                else if (isdigit(formula[i])) {
                    count=count*10+formula[i]-'0';
                }
                else if (islower(formula[i])) {
                    name+=formula[i];
                }
            }
        }
        if (name!="") {
            s.push(make_pair(name,count==0?1:count));
            name="";
            count=0;
        }
        while (!s.empty()) {
            m[s.top().first]+=s.top().second;
            s.pop();
        }
        string res="";
        for (auto p:m) {
            res+=p.first;
            if (p.second!=1) res+=to_string(p.second);
        }
        return res;
    }
};