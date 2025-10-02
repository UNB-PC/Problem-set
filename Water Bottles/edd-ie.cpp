class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = numBottles;
        int rem = 0;
        while(numBottles >= numExchange){
            rem = numBottles%numExchange;

            numBottles /= numExchange;
            sum += numBottles;

            numBottles += rem;
            
        }
        return sum;
    }
};
