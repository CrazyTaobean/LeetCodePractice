#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size() - 1;
        int n = nums2.size() - 1;
        if (!(m+1)) {
            for (int i = 0; i < n + 1; ++i) {
                nums1.push_back(nums2[i]);
            }
            int mid = nums1.size();
            if (mid%2==1) {
                return nums1[mid/2];
            } else {
                return (nums1[mid/2] + nums1[mid/2-1])/2.0;
            }
        }
        int cur = m + n + 1;
        for (int i = 0; i <= n; ++i) {
            nums1.push_back(0);
        }
        for (; m>=0 && n >=0;) {
            if (nums1[m] > nums2[n]) {
                nums1[cur--] = nums1[m--];
            } else{
                nums1[cur--] = nums2[n--];
            }
        }
        if (n+1) {
            while (n+1) {
                nums1[cur--] = nums2[n--];
            }
        }
        int mid = nums1.size();
        if (mid%2==1) {
            return nums1[mid/2];
        } else {
            return (nums1[mid/2] + nums1[mid/2-1])/2.0;
        }
    }
};

int main() {
    Solution s;
//    vector<int> nums1;nums1.push_back(1);nums1.push_back(3);
    vector<int> nums1;;
    vector<int> nums2;nums2.push_back(1);nums2.push_back(3);
    double res = s.findMedianSortedArrays(nums1, nums2);
    cout << res;
}