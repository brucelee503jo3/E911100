#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        TreeNode *left = NULL;
        TreeNode *right = NULL;
        TreeNode *parent = NULL;
        int val;
};



class Tree {
    public:
        TreeNode *root = NULL;
        void Insert(int val) {
            TreeNode *newnode = new TreeNode();
            TreeNode *cur = root;
            newnode->val = val;
            if(root == NULL) {
                root = newnode;
            }
            else {
                while(true) {
                    if(val < cur->val) {
                        if(cur->left == NULL) {
                            newnode->parent = cur;
                            cur->left = newnode;
                            break;
                        }
                        else {
                            cur = cur->left;
                        }
                    }
                    else {
                        if(cur->right == NULL) {
                            newnode->parent = cur;
                            cur->right = newnode;
                            break;
                        }
                        else {
                            cur = cur->right;
                        }
                    }
                }
            }
        }
        void vlr(TreeNode *t) {
            TreeNode *cur = t;
            cout << cur->val << " ";
            if(cur->left!=NULL)
                vlr(cur->left);
            if(cur->right!=NULL)
                vlr(cur->right);
            return;
        }
        void lvr(TreeNode *t) {
            TreeNode *cur = t;
            if(cur->left!=NULL)
                lvr(cur->left);
            cout << cur->val << " ";
            if(cur->right!=NULL)
                lvr(cur->right);
            return;
        }
        void lrv(TreeNode *t) {
            TreeNode *cur = t;
            if(cur->left!=NULL)
                lrv(cur->left);
            if(cur->right!=NULL)
                lrv(cur->right);
            cout << cur->val << " ";
            return;
        }
        void decending(TreeNode *t) {
            TreeNode *cur = t;
            if(cur->right!=NULL)
                decending(cur->right);
        cout << cur->val << " ";  
            if(cur->left!=NULL)
                decending(cur->left);  
            return;
        }
};

int main() {
    Tree t;
    t.Insert(47);    
    t.Insert(36);
    t.Insert(84);
    t.Insert(25);
    t.Insert(42);
    t.Insert(75);
    t.Insert(29);
    t.Insert(17);
    t.Insert(39);
    t.Insert(45);
    t.Insert(66);
    t.Insert(79);
    cout << "pre-order ";
    t.vlr(t.root);
    cout << endl;
    cout << "in-order ";
    t.lvr(t.root);
    cout << endl;
    cout << "post-order ";
    t.lrv(t.root);
    cout << endl;
    cout << "decending order ";
    t.decending(t.root);
}
