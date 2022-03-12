#include <vector>
#include <stack>
#include <unordered_set>

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

/*
class Solution {
public:
    void postOrder(Node *root, vector<int> &res) {
        if(root==nullptr) {
            return;
        }
        for(auto & ch : root->children) {
            postOrder(ch, res);
        }
        res.emplace_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> res;
        postOrder(root, res);
        return res;
    }
};*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        stack<Node*> stk;
        vector<int> res;
        if(root==nullptr) return res;
        unordered_set<Node*> visited;
        stk.emplace(root);
        while(!stk.empty()) {
            Node * node = stk.top();
            if(visited.count(node) || node->children.size()==0) {
                res.emplace_back(node->val);
                stk.pop();
                continue;
            }
            for(auto ch=node->children.rbegin() ; ch!=node->children.rend(); ch++) {
                stk.emplace(*ch);
            }
            visited.emplace(node);
        }
        return res;
    }
};