class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> t(nums.size());
        for (int i=0;i<nums.size();i++) t[i]=to_string(nums[i]);
        sort(t.begin(),t.end(),[](string a, string b){return a+b>b+a;});
        string res="";
        for (int i=0;i<t.size();i++) res+=t[i];
        int i=0;
        while (i<res.size()-1 && res[i]=='0') i++;
        return res.substr(i);
    }
    
};