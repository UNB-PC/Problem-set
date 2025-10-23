class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        using namespace std;
        int l = 0;
        unordered_set<char> lookup{};
        int longest = 0;

        for(int r = 0;  r < s.length(); r++){
            while(lookup.contains(s[r])){
                lookup.erase(s[l]);
                l++;
            }

            longest = std::max(longest, (r-l)+1);
            lookup.insert(s[r]);
        }
        return longest;
    }
};
