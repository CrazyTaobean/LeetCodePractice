/*
 * there are some error happen in leetcode, i don't know why now.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;
        if (m==0) {
            for (int i = 0; i < n; ++i) {
                nums1.push_back(nums2[i]);
            }
        }
        if (n==0) {
            return;
        }
        int l,r = 0;
        int less=0;
        if (m<=n) less = m;
        else less = n;
        for (; l < less && r < less;) {
            if (nums1[l] < nums2[r]) {
                res.push_back(nums1[l++]);
            } else{
                res.push_back(nums2[r++]);
            }
        }
        if (l<m) {
            for (int i = l; i < m; ++i) {
                res.push_back(nums1[i]);
            }
        }
        if (r<n) {
            for (int i = r; i < n; ++i) {
                res.push_back(nums2[i]);
            }
        }
        for (int k = 0; k < nums1.size(); ++k) {
            nums1[k] = res[k];
        }
        for (int i = 0; i < nums1.size(); ++i) {
        	cout << nums1[i] << endl;
		}
    }
};

int main() {
    Solution s;
    vector<int> nums1;nums1.push_back(1);nums1.push_back(2);nums1.push_back(3);nums1.push_back(0);nums1.push_back(0);nums1.push_back(0);
    vector<int> nums2;nums2.push_back(2);nums2.push_back(5);nums2.push_back(6);
    s.merge(nums1,3,nums2,3);
}
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        if (m==0) {
            for (int i = 0; i < n; ++i) {
                nums1[i] = nums2[i];
            }
        }
        if (n==0) {
            return;
        }
        int cur = m + n - 1;
        int l = m - 1;
        int r = n - 1;
        for (int i = 0; l>=0 && r>=0; ++i) {
            if (nums1[l] < nums2[r]) {
                nums1[cur--] = nums2[r--];
            } else{
                nums1[cur--] = nums1[l--];
            }
        }
        if (r>=0) {
            while (r+1){
                nums1[cur--] = nums2[r--];
            }
        }
        for (int i = 0; i < nums1.size(); ++i) {
            cout << nums1[i] << endl;
        }
    }
};

int main() {
    Solution s;
//    vector<int> nums1;nums1.push_back(1);nums1.push_back(2);nums1.push_back(3);nums1.push_back(0);nums1.push_back(0);nums1.push_back(0);
    vector<int> nums1;nums1.push_back(2);nums1.push_back(0);
//    vector<int> nums2;nums2.push_back(2);nums2.push_back(5);nums2.push_back(6);
    vector<int> nums2;nums2.push_back(1);
    s.merge(nums1,1,nums2,1);
}