class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        std::stack<int> stack;


        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            while(!stack.empty() && temperatures[i] > temperatures[stack.top()]){
                ans[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }

        while(!stack.empty()){
            ans[stack.top()] = 0;
            stack.pop();
        }

        return ans;
    }
};
