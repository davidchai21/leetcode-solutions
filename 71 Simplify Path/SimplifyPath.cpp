class Solution {
public:
    string simplifyPath(string path) {
        string t,res="";
        stringstream s(path);
        stack<string> a;
        while (getline(s,t,'/'))
        {
            if (t=="" || t==".") continue;
            if (t==".." && !a.empty()) a.pop();
            else if (t!="..") a.push(t);
        }
        while (!a.empty()) {res=a.top()+"/"+res; a.pop();}
        if (res.empty()) return "/";
        return "/"+res.substr(0,res.size()-1);
    }
};