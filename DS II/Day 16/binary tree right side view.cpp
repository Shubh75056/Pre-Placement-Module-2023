class Solution {
    int mxl=-1;
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans,0);
        return ans;
    }
    
    void dfs(TreeNode* root, vector<int>& ans,int level)
    {
        if(root==nullptr) return;
        if(mxl<level)
        {
            ans.push_back(root->val);
            mxl = level;
        }
        dfs(root->right,ans,level+1);
        dfs(root->left,ans,level+1);
    }
};