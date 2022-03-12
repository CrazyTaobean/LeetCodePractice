#include <vector>

using namespace std;

class Solution {
public:
    int n;
    int lnode[100001];
    int rnode[100001];
    int size[100001];
    void dfs(int x) {
        size[x] = 1;
        if(lnode[x]) {
            dfs(lnode[x]);
            size[x]+=size[lnode[x]];
        }
        if(rnode[x]) {
            dfs(rnode[x]);
            size[x]+=size[rnode[x]];
        }
    }
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        for(int i=1; i<n; i++) {
            if(!lnode[parents[i]])
                lnode[parents[i]] = i;
            else
                rnode[parents[i]] = i;
        }
        dfs(0);
        long long maxScore = 0;
        int res = 0;
        for(int i=0; i<n; i++) {
            int p1, p2,p3;

            if(!i) {
                p1=1;
            }else {
                p1=n-size[i];
            }
            if(lnode[i]==0) {
                p2=1;
            }else{
                p2=size[lnode[i]];
            }
            if(rnode[i]==0) {
                p3=1;
            }else{
                p3=size[rnode[i]];
            }
            if(1LL*p1*p2*p3 > maxScore){
                maxScore = 1LL*p1*p2*p3;
                res=0;
            }
            if(1LL*p1*p2*p3 == maxScore) {
                ++res;
            }
        }
        return res;
    }
};

int main() {
    vector<int> parrents;
    parrents.emplace_back(-1);
    parrents.emplace_back(2);
    parrents.emplace_back(0);
    parrents.emplace_back(2);
    parrents.emplace_back(0);
    Solution s;
    s.countHighestScoreNodes(parrents);
}