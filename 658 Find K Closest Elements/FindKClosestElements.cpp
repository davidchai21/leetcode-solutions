class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        if (x<=arr[0]) {
            for (int i=0;i<k;i++) res.push_back(arr[i]);
            return res;
        }
        if (x>=arr.back()) {
            for (int i=arr.size()-k;i<arr.size();i++) res.push_back(arr[i]);
            return res;
        }
        int left=0;
        int right=arr.size()-1;
        while (left<right) {
            int a=abs(arr[left]-x);
            int b=abs(arr[right]-x);
            if (a>b) left++;
            else right--;
        }
        right++;
        while (left>=0 && right<arr.size() && k>0) {
            int a=abs(arr[left]-x);
            int b=abs(arr[right]-x);
            if (a<=b) left--;
            else right++;
            k--;
        }
        while (k) {
            if (left>=0) left--;
            else right++;
            k--;
        }
        for (int i=left+1;i<right;i++) {
            res.push_back(arr[i]);
        }
        return res;
    }
};