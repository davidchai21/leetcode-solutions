class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int res=inner_product(price.begin(),price.end(),needs.begin(),0);
        for (vector<int> s:special) {
            vector<int> t=helper(s,needs);
            if (t.empty()) continue;
            res=min(res,shoppingOffers(price,special,t)+s.back());
        }
        return res;
    }
    vector<int> helper(vector<int> a, vector<int> b) {
        vector<int> res(b.size());
        for (int i=0;i<b.size();i++) {
            int t=b[i]-a[i];
            if (t<0) return vector<int>();
            res[i]=t;
        }
        return res;
    }
};