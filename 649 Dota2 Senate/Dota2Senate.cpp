class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r,d;
        for (int i=0;i<senate.size();i++) senate[i]=='R'?r.push(i):d.push(i);
        while (!r.empty() && !d.empty()) {
            int a=r.front();
            int b=d.front();
            r.pop();
            d.pop();
            a<b?r.push(a+senate.size()):d.push(b+senate.size());
        }
        return (r.size()>d.size())?"Radiant":"Dire";
    }
};