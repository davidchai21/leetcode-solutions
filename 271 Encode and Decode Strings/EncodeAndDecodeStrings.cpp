class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res="";
        for (int i=0;i<strs.size();i++) {
            res+=to_string(strs[i].size())+"#"+strs[i];
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int i=0;
        vector<string> res;
        while (i<s.size()) {
            int j=i+1;
            while (s[j]!='#') j++;
            int len=stoi(s.substr(i,j-i));
            string t=s.substr(j+1,len);
            res.push_back(t);
            i=j+len+1;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));