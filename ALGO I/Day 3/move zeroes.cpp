#include <algorithm>

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        vector<int>::iterator pos = std::remove(nums.begin(), nums.end(), 0);
        std::fill(pos, nums.end(), 0);
    }
};