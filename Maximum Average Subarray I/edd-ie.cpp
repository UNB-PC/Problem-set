class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        using namespace std;
        double sum = 0;
        double ave = 0;

        for(int i = 0; i < k; i++){
            sum += nums[i];
        }

        ave = sum/k;

        for(int i = k; i < nums.size(); i++){
            sum += nums[i];
            sum -= nums[i - k];
            ave = max(ave, sum/k);
        }

        return ave;
    }
};
