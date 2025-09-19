ﾳass Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> data;
        data.reserve(nums.size());

        for(auto x:nums)
            data.insert(x);
        
        int longest = 0;
        for(auto x:data){
            if(!data.contains(x-1)){
                int y = x+1;
                while(data.contains(y))
                    y++;
                longest = std::max(longest, y-x);
            }
        }
        return longest;
    }
};
