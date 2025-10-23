class Solution {
public:
    int maxProfit(vector<int>& prices) {
        using namespace std;

        int profit = 0;
        int buy = 0;
        int total = 0;

        for(int sell = 1; sell < prices.size(); sell++){
            if(prices[sell-1] > prices[sell]){
                buy = sell;
                total += profit;
                profit = 0;
            }
            else{
                profit = max(profit, prices[sell] - prices[buy]);
            }
        }

        // incase the array is sorted in ascending order thus 
        // loop terminates without adding profit to total 
        return profit+total;
        
    }
};
