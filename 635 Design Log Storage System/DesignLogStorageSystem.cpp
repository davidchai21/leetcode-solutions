class LogSystem {
public:
    LogSystem() {
        h["Year"]=0;
        h["Month"]=1;
        h["Day"]=2;
        h["Hour"]=3;
        h["Minute"]=4;
        h["Second"]=5;
    }
    
    void put(int id, string timestamp) {
        m[timestamp]=id;
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        vector<int> res;
        for (auto p:m) {
            string t=p.first;
            if (g(s,t,gra) && sm(e,t,gra)) res.push_back(p.second);
        }
        return res;
    }
private:
    unordered_map<string,int> m;
    unordered_map<string,int> h;
    bool g(string b, string e, string gra) {
        vector<int> x=split(b);
        vector<int> y=split(e);
        for (int i=0;i<=h[gra];i++)
        {
            if (x[i]>y[i]) return false;
            else if (x[i]<y[i]) return true;
        }
        return true;
    }
    bool sm(string b, string e, string gra) {
        vector<int> x=split(b);
        vector<int> y=split(e);
        for (int i=0;i<=h[gra];i++)
        {
            if (x[i]<y[i]) return false;
            else if (x[i]>y[i]) return true;
        }
        return true;
    }
    vector<int> split(string a) {
        vector<int> res(6);
        istringstream ss(a);
        string b;
        int i=0;
        while (getline(ss,b,':')) {
            res[i++]=stoi(b);
        }
        return res;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */