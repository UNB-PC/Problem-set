class NumArray {
public:
    vector<int> x;
    NumArray(vector<int>& nums) {
        x = nums;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for(int i = left; i < right+1; i++){
            sum += x[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
