class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0, n = heights.size();
        int l = 0, r = n - 1;
        while(l<r){
            int area = (r-l)*min(heights[l],heights[r]);
            ans = max(ans, area);

            heights[l]>=heights[r]? r-- : l++;
        }
        return ans;
    }
};