#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

//recursion
/*
class Solution {
public:
    void preOrder(Node *root, vector<int> &res) {
        if (root == nullptr)
            return;
        res.emplace_back(root->val);
        for (auto & ch : root->children){
            preOrder(ch, res);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> res;
        preOrder(root, res);
        return res;
    }
};*/

//iteration
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (root == nullptr)
            return res;
        stack<Node*> stk;
        stk.emplace(root);
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            res.emplace_back(root->val);
            for (auto it = root->children.rbegin(); it != root->children.rend(); it++) {
                stk.emplace(*it);
            }
        }
        return res;
    }
};