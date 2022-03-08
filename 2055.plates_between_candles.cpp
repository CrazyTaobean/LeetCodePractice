#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries) {
        int n = s.size();
        int sum = 0;
        vector<int> preSum = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                sum++;
            }
            preSum[i] = sum;
        }
        vector<int> left(n);
        for (int j = 0, l = -1; j < n; ++j) {
            if (s[j] == '|')
                l = j;
            left[j] = l;
        }
        vector<int> right(n);
        for (int k = n - 1, r = -1; k >= 0; --k) {
            if (s[k] == '|')
                r = k;
            right[k] = r;
        }
        for(int i = 0; i < 10; i++) {
            cout << left[i] << " " << right[i] <<endl;
        }
        vector<int> ans;
        for (auto &query:queries) {
            int x = right[query[0]], y = left[query[1]];
            ans.push_back(x==-1||y==-1||x>=y?0:preSum[y] - preSum[x]);
        }
        return ans;
    }
};

int main() {
    string s = "**|**|***|";
    vector<int> v1;v1.push_back(2);v1.push_back(5);
    vector<int> v2;v2.push_back(5);v2.push_back(9);
    vector<vector<int>> vec;
    vec.push_back(v1);
    vec.push_back(v2);
    Solution solution;
    vector<int> res = solution.platesBetweenCandles(s, vec);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
}