  class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        int minOne = INT_MAX;
        int minTwo = INT_MAX;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] < minOne)
                minOne = nums[i];
            if(nums[i] > minOne)
                minTwo = min(nums[i],minTwo);
            if(nums[i] > minTwo)
                return true;
        }
        return false;
    }
};