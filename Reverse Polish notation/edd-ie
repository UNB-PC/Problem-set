class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stack;

        for(string a : tokens){
            if (a != "+" && a != "-" && a != "*" && a != "/") {
                stack.push(std::stoi(a));
            }
            else{
                int y = stack.top();
                stack.pop();
                int x = stack.top();
                stack.pop();

                if (a == "+") {
                    stack.push(x + y);
                } else if (a == "-") {
                    stack.push(x - y);
                } else if (a == "*") {
                    stack.push(x * y);
                } else{
                    stack.push(x / y);
                } 
            }
        } 
        return stack.top();      
    }
};
