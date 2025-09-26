class Solution {
public:
    
    int trap(vector<int>& height) {
        int l = 0, lmax = 0;
        int r = height.size()-1, rmax = 0;
        int vol = 0;

        while(l<r){
            if(height[l] < height[r]){
                if(height[l] > lmax)
                    lmax = height[l];
                else{
                    vol += lmax - height[l];
                }
                l++;
            }
            else{
                if(height[r] > rmax)
                    rmax = height[r];
                else{
                    vol += rmax - height[r];
                }
                r--;
            }
        }

        return vol;
    }
};
