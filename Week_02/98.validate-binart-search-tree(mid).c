/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//中序遍历
bool IsValidBSTTreeIterate(long int min, struct TreeNode *root, long int max)
{
    /* 最后为NULL，证明没有提前返回的，结束，返回true */
    if (root == NULL) {
        return true;
    }

    /* 需要提前返回false的情况 */
    if (root->val <= min || root->val >= max) {
        return false;
    }

    return IsValidBSTTreeIterate(min, root->left, root->val) && 
        IsValidBSTTreeIterate(root->val, root->right, max);
}

bool isValidBST(struct TreeNode* root){
    /* 这里用long的min和max做为基础的最大最小值，避免节点中存在int min或int max[2147483647]时，无法比较大小（只能相等）。注意函数入参是long int，不要用int，long min和max会被截断 */
    return IsValidBSTTreeIterate(LONG_MIN, root, LONG_MAX);    
}