bool validate(struct TreeNode* root, long long min, long long max) {
    if (root == NULL)
        return true;
    if (root->val <= min || root->val >= max)
        return false;
    return validate(root->left, min, root->val) &&
           validate(root->right, root->val, max);
}
bool isValidBST(struct TreeNode* root) {
    return validate(root, LLONG_MIN, LLONG_MAX);
}