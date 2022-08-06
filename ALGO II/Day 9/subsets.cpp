class Solution {
public:
    void subsetsUtil(vector<int>& nums, vector<vector<int>>& result, vector<int>& subset, int index) {
        result.push_back(subset);
        for(int i = index; i < nums.size(); i++){
            subset.push_back(nums[i]);
            subsetsUtil(nums, result, subset, i + 1);
            subset.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> result;
        subsetsUtil(nums, result, subset, 0);
        return result;
    }
};