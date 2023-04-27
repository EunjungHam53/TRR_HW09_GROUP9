#include <iostream>
using namespace std;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
};


TreeNode* newNode(int key) {
    TreeNode* node = new TreeNode;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}


int findMin(TreeNode* root) {
    if (root == NULL) {
        return INT_MAX;
    } else if (root->left == NULL) {
        return root->key;
    } else {
        return findMin(root->left);
    }
}

int main() {
    TreeNode* root = newNode(29);
    root->left = newNode(12);
    root->left->left = newNode(1);
    root->left->right = newNode(22);
    root->left->left->right = newNode(3);
    root->left->right->left = newNode(13);
    root->left->left->right->right = newNode(9);
    root->left->right->left->right = newNode(20);
    root->left->left->right->left  = newNode(2);
    root->left->right->left->right->left = newNode(16);
    root->left->left->right->right->left = newNode(7);

    int minKey = findMin(root);
    cout << " lock min là: " << minKey << endl;

    return 0;
}
