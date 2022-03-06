#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& s, int t) {
        int n = s.size();
        vector<int> res;
        // 两个剪枝
        if(2 * t + 1 > n) return res;
        if(t == 0) {
            for(int i = 0;i < n;i ++) res.push_back(i);
            return res;
        }
        int o1,o2;
        o1 = 0;// 前面递增的个数
        o2 = 0;// 后面递减的个数

        for(int i = 1;i <= t;i ++) {
            if(s[i] > s[i - 1]) o1 ++;
        }
        for(int i = t + 1;i <= t + t;i ++) {
            if(s[i] < s[i - 1]) o2 ++;
        }

        for(int p = t, i = 0, j = 2 * t;;p ++) {
            if(!o1 && !o2) res.push_back(p);
            if(j + 1 == n) break;
            if(s[i] < s[i + 1]) o1 --;
            if(s[p] < s[p + 1]) o1 ++;
            if(s[p] > s[p + 1]) o2 --;
            if(s[j + 1] < s[j]) o2 ++;
            i ++ , j ++;
        }
        return res;
    }
};
/**
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int> &security, int time) {
        vector<int> res;
        if (time > security.size() * 2 || security.size()==0) {
            return res;
        }
        for (int i = 0; i < security.size(); ++i) {
            int lp = i, rp = i;
            bool flag = true;
            if (i-time<0) {
                continue;
            }
            if (security.size() - i - 1 < time) {
                return res;
            }
            for (int j = lp - 1, index = 0; index < time; ++index, --j) {
                if (security[j] < security[lp--]) {
                    flag=!flag;
                    break;
                }
            }
            if (flag){
                for (int k = rp + 1, index = 0; index < time; ++index, ++k) {
                    if (security[k] < security[rp++]) {
                        flag=!flag;
                        break;
                    }
                }
            }
            if (flag)
                res.push_back(i);
        }
        return res;
    }
};*/

int main() {
    vector<int> security;
    security.push_back(1);
    security.push_back(1);
    security.push_back(1);
    security.push_back(1);
    security.push_back(1);
//    security.push_back(3);
//    security.push_back(3);
//    security.push_back(3);
//    security.push_back(5);
//    security.push_back(6);
//    security.push_back(2);
    int time = 0;
    Solution solution;
    vector<int> res = solution.goodDaysToRobBank(security, time);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i];
    }
    cout << endl;
}