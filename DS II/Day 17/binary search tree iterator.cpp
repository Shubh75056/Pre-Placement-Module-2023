class BSTIterator {
    vector<int> A;
    int p = 0;
    void init(TreeNode* node) {
        if(!node) return;
        init(node->left);
        A.push_back(node->val);
        init(node->right);
    }
public:
    BSTIterator(TreeNode* root) {
        A.push_back(INT_MIN);
        init(root);
    }
    
    bool hasNext() {
        return p + 1 < A.size();
    }
    
    int next() {
        return A[++p];
    }
    
    bool hasPrev() {
        return p > 1;
    }
    
    int prev() {
        return A[--p];
    }
};