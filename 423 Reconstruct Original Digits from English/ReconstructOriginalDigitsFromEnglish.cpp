class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char,int> t;
        for (int i=0;i<s.size();i++)
        {t[s[i]]++;}
        vector<int> res(10,0);
        res[0]+=t['z'];
        res[2]+=t['w'];
        res[4]+=t['u'];
        res[6]+=t['x'];
        res[8]+=t['g'];
        res[7]=t['s']-res[6];
        res[5]=t['v']-res[7];
        res[3]=t['h']-res[8];
        res[1]=t['o']-res[0]-res[2]-res[4];
        res[9]=t['i']-res[8]-res[6]-res[5];
        string a="";
        for (int i=0;i<10;i++)
        {
            for (int j=0;j<res[i];j++)
            {a+=to_string(i);}
        }
        return a;
    }
};