class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int x = 0;
        int y = 0;
        std::stack<int> stack;

        while(y<popped.size()){
            if(x==pushed.size()){
                if(stack.top() != popped[y]) 
                    return false;
                else{
                    stack.pop();
                    y++;
                }
            }
            else if(pushed[x] != popped[y]){
                if(!stack.empty() && stack.top()== popped[y]){
                    stack.pop();
                    y++;
                }
                else stack.push(pushed[x++]);
            }
            else{
                x++;
                y++;
            }
        }
        return true;
    }
};
