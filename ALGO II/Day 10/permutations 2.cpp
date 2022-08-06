class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> reval;
        std::sort(nums.begin(),nums.end());
        reval.push_back(nums);
        while(nextPermutation(nums)){
            reval.push_back(nums);
        }
        return reval;
    }
private:
    bool nextPermutation(vector<int>& nums){
        int vio_index(nums.size()-2);
        while(vio_index>=0 && nums[vio_index] >= nums[vio_index+1]){
            -- vio_index;
        }
        if(vio_index == -1) return false;
        std::reverse(nums.begin()+vio_index+1, nums.end());
        //find the upper bound value
        auto iter = std::upper_bound(nums.begin()+vio_index+1,nums.end(),nums[vio_index]);
        std::swap(nums[vio_index],*iter);
        return true;
    }
};