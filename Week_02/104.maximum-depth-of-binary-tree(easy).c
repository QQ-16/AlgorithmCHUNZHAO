/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int DFS(struct TreeNode* node)
{
    int curMax = 0;
    if (node == NULL) {
        return 0;
    }
    int left = DFS(node->left);
    int right = DFS(node->right);
    curMax = left > right ? left : right;
    return curMax + 1;
}

int maxDepth(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }

    int maxDepth = DFS(root);
    return maxDepth;
}