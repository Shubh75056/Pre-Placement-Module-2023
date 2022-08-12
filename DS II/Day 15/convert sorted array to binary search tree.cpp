class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }
        auto p_root_node = new(TreeNode*);
        helper(p_root_node, nums, 0, nums.size()-1);
        return *p_root_node;
    }

    void helper(TreeNode** node, vector<int>& nums, int left_bound, int right_bound) {
        if (left_bound > right_bound) {
            return;
        }
        int mid = (left_bound+right_bound)/2;
        *node = new TreeNode(nums[mid]);
        helper(&(*node)->left, nums, left_bound, mid-1);
        helper(&(*node)->right, nums, mid+1, right_bound);
    }
};