class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max = nums[0];

        if(nums.size() == 1 && nums[0] == 0)
            return true;

        for(int i = 0; i < nums.size(); i++){
            if(max <= i && nums[i] == 0)
                return false;

            if(i + nums[i] > max)
                max = i + nums[i];

            if(max >= nums.size() - 1)
                return true;
        }

        return false;
    }
};