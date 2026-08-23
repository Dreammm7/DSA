class Solution {
public:
    int rob(vector<int>& nums) {
        int rob_prev2 = 0; // Max profit up to 2 houses ago
        int rob_prev1 = 0; // Max profit up to 1 house ago
        
        for (int num : nums) {
            int current_max = max(rob_prev1, rob_prev2 + num);
            rob_prev2 = rob_prev1;
            rob_prev1 = current_max;
        }
        
        return rob_prev1;
    }
};
