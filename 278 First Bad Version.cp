// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned int start = 0;
        unsigned int end = n;
        
        while (start < end){
            unsigned int mid = (start+end)/2;
            if (isBadVersion(mid)!= isBadVersion(mid+1)) return mid+1;
            else if (isBadVersion(mid)!= isBadVersion(mid-1)) return mid;
            else if (isBadVersion(mid)==isBadVersion(mid+1) && isBadVersion(start)!=isBadVersion(mid)){
                end = mid;
            }
            else if (isBadVersion(mid)==isBadVersion(mid+1) && isBadVersion(end)!=isBadVersion(mid)){
                start = mid+1;
            }
        }
        return 0;
    }
};
