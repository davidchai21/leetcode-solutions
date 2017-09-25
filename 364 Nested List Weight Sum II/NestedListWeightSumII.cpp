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
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int l=getLevel(nestedList);
        int res=0;
        helper(nestedList,l,res);
        return res;
    }
    void helper(vector<NestedInteger>& a, int l, int& res) {
        for (int i=0;i<a.size();i++) {
            if (a[i].isInteger()) res+=a[i].getInteger()*l;
            else helper(a[i].getList(),l-1, res);
        }
    }
    int getLevel(vector<NestedInteger>& a) {
        if (a.size()==0) return 0;
        int res=0;
        for (int i=0;i<a.size();i++) {
            if (a[i].isInteger()==false) res=max(res,getLevel(a[i].getList()));
        }
        return res+1;
    }
};