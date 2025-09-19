class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int counter = 0;

        for(auto x : nums){
            if(x==0){
                counter++;
                if(counter > 1) break;
            }
            else product*=x;
        }
        
        vector<int> ans(nums.size());
        std::transform(nums.begin(), nums.end(), ans.begin(),
            [product, counter](int k) {
                if(counter > 1) return 0;
                if(k==0) return product;
                if(counter == 1) return 0;
                return product/k;
            });
        return ans;
    }
};
