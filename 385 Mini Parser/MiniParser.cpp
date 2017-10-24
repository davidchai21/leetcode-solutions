/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s[0]=='-' || isdigit(s[0])) return NestedInteger(stoi(s));
        stack<NestedInteger> st;
        st.push(NestedInteger());
        int i=0;
        while (i<s.size()) {
            if (s[i]=='[') {
                st.push(NestedInteger());
                pair<bool,int> t=getnum(s,i+1);
                if (t.first) st.top().add(stoi(s.substr(i+1,t.second-i-1)));
                i=t.second;
            }
            else if (s[i]==',') i++;
            else if (s[i]==']') {
                NestedInteger p=st.top();
                st.pop();
                if (st.size()==1) return p;
                st.top().add(p);
                i++;
            }
            else {
                pair<bool,int> t=getnum(s,i);
                if (t.first) st.top().add(stoi(s.substr(i,t.second-i)));
                i=t.second;
            }
        }
        return st.top();
    }
    pair<bool,int> getnum(string s, int pos) {
        int i=pos;
        while (i<s.size() && (isdigit(s[i]) || s[i]=='-')) i++;
        if (i==pos) return {false,i};
        else return {true,i};
    }
};