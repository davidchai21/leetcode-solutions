class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int left=0;
        int right=n-1;
        while (left<=right) {
            int mid=left+(right-left)/2;
            if (citations[mid]==n-mid) return n-mid;
            else if (citations[mid]>n-mid) right=mid-1;
            else left=mid+1;
        }
        return n-right-1;
    }
};