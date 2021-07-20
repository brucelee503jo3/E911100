#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        TreeNode *left = NULL;
        TreeNode *right = NULL;
        TreeNode *parent = NULL;
        char val;
};

class Tree {
    public:
        TreeNode *root = NULL;
        vector<TreeNode*> stack;
        void Insert(char val) {
            TreeNode *newnode = new TreeNode();
            newnode->val = val;
            if(val == '+' || val == '-' || val == '*' || val == '/') {
                newnode->right = stack[stack.size()-1];
                stack[stack.size()-1]->parent = newnode;
                stack.pop_back();
                newnode->left = stack[stack.size()-1];
                stack[stack.size()-1]->parent = newnode;
                stack.pop_back();
                root = newnode;
                stack.push_back(newnode);
            }
            else {
                stack.push_back(newnode);
            }
        }
        void vlr(TreeNode *t) {
            TreeNode *cur = t;
            cout << cur->val;
            if(cur->left!=NULL)
                vlr(cur->left);
            if(cur->right!=NULL)
                vlr(cur->right);
            return;
        }
        void inOrder(TreeNode *treePtr) {
            TreeNode *cur = t;
            if(cur->data == '+' || cur->data == '-' || cur->data == '*' || cur->data == '/')
                cout << '(';
            if(cur->left!=NULL)
                inOrder(cur->left);
            cout << cur->val;
            if(cur->right!=NULL)
                inOrder(cur->right);
            if(cur->data == '+' || cur->data == '-' || cur->data == '*' || cur->data == '/')
                cout << ')';
            return;
        }
        void lrv(TreeNode *t) {
            TreeNode *cur = t;
            if(cur->left!=NULL)
                lrv(cur->left);
            if(cur->right!=NULL)
                lrv(cur->right);
            cout << cur->val;
            return;
        }
};

int main() {
    Tree t;
    t.Insert('a');
    t.Insert('b');
    t.Insert('+');
    t.Insert('c');
    t.Insert('*');
    t.Insert('7');
    t.Insert('+');
    t.lvr(t.root);
    cout << endl;
    Tree x;
    x.Insert('9');
    x.Insert('5');
    x.Insert('+');
    x.Insert('6');
    x.Insert('*');
    x.Insert('3');
    x.Insert('5');
    x.Insert('+');
    x.Insert('8');
    x.Insert('/');
    x.Insert('-');
    x.Insert('7');
    x.Insert('8');
    x.Insert('2');
    x.Insert('+');
    x.Insert('*');
    x.Insert('4');
    x.Insert('/');
    x.Insert('+');
    x.Insert('6');
    x.Insert('4');
    x.Insert('+');
    x.Insert('5');
    x.Insert('/');
    x.Insert('-');
    x.lrv(x.root);
    cout << endl;
    x.lvr(x.root);
}
