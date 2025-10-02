class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = height.size()-1;

        while(left < right){
            if(height[left] > height[right]){
                ans = std::max((height[right]*(right-left)), ans);
                right--;
            }
            else{
                ans = std::max((height[left]*(right-left)), ans);
                left++;
            }
        }

        return ans;
    }
};
