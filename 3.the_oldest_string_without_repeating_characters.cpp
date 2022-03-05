#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

//slide window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> occ;                    // save the largest substring
        int size = s.size();                        // the length of string "s"
        int ans = 0;                                // save the max length
        int n = -1;
        for (int i = 0; i < size; ++i) {            // traversal string "s"
            if ((size - i - 1) < ans) {
                return ans;
            }
            if (i != 0) {
                occ.erase(s[i - 1]);              // move left pointer one step after every loop
            }
            while (n + 1 < size && !occ.count(s[n + 1])) {
                occ.insert(s[n + 1]);             // insert value that not in occ
                n++;
            }
            ans = max(ans, n - i + 1);
        }
        return ans;
    }
    int second_way
    (string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            while (lookup.find(s[i]) != lookup.end()){
                lookup.erase(s[left]);
                left ++;
            }
            maxStr = max(maxStr,i-left+1);
            lookup.insert(s[i]);
        }
        return maxStr;
    }
};

int main() {
    string s = "abcav";
    Solution *solution = new Solution();
    int x = solution->second_way(s);
    cout << x << endl;
}