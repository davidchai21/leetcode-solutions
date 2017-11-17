class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m=image.size();
        if (m==0) return 0;
        int n=image[0].size();
        if (n==0) return 0;
        int upper=findx(image,x,m,n,true);
        int lower=findx(image,x,m,n,false);
        int left=findy(image,y,m,n,true);
        int right=findy(image,y,m,n,false);
        return (right-left)*(lower-upper);
    }
    int findx(vector<vector<char> > image, int x, int m, int n, bool upper) {
        int i=upper?0:x;
        int j=upper?x:m;
        while (i<j) {
            int mid=i+(j-i)/2;
            int k=0;
            for (;k<n;k++) {
                if (image[mid][k]=='1') break;
            }
            if (k<n) {
                if (upper) j=mid;
                else i=mid+1;
            }
            else {
                if (upper) i=mid+1;
                else j=mid;
            }
        }
        return i;
    }
    int findy(vector<vector<char> > image, int y, int m, int n, bool left) {
        int i=left?0:y;
        int j=left?y:n;
        while (i<j) {
            int mid=i+(j-i)/2;
            int k=0;
            for (;k<m;k++) {
                if (image[k][mid]=='1') break;
            }
            if (k<m) {
                if (left) j=mid;
                else i=mid+1;
            }
            else {
                if (left) i=mid+1;
                else j=mid;
            }
        }
        return i;
    }
};