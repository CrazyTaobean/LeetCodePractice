#include <iostream>
#include <vector>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//recursion
/*class Solution {
public:
    void preOrder(TreeNode *root, vector<int> &res) {
        if (root == nullptr)
            return;
        res.push_back(root->val);
        preOrder(root->left, res);
        preOrder(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        preOrder(root, res);
        return res;
    }
};*/
//iteration
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        if (root == nullptr)
            return res;
        while (!stk.empty() || root != nullptr) {
            while (root != nullptr) {
                res.emplace_back(root->val);
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            root = root->right;
        }
        return res;
    }
};