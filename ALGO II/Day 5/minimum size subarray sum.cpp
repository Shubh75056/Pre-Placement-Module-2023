class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right = 0;
        int res = INT_MAX;
        int cnt = 0;
        while(right < nums.size()){
            cnt += nums[right];
            while(left <= right && cnt >= s){
                res = min(res, right-left+1);
                cnt -= nums[left];
                left++;
            }
            right++;
        }
        return res == INT_MAX ? 0 : res;
    }
};
