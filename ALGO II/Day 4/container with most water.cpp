class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() == 0){
            return 0;
        }

        int left = 0;
        int right = height.size() - 1;
        int area = 0;

        while(left < right){
            area = max(area, (right - left) * min(height[left], height[right]));
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return area;
    }
};