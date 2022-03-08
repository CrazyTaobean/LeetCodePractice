#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num==0) return "0";
        bool isNegative = false;
        if (num < 0) {isNegative = 1; num*=(-1);}
        string s;
        while (num > 0) {
            s.push_back(num%7+'0');
            num/=7;
        }
        if (isNegative){
            num*=(-1);
            s.push_back('-');
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    int num = 100;
    Solution s;
    string res = s.convertToBase7(num);
    cout << res << endl;
}