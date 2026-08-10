class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN;
        int currsum=0;
        for (int i=0; i< nums.size() ; i++){
            currsum += nums[i];
            maxSum = max(currsum , maxSum);
            if (currsum < 0 ){
                currsum = 0;
            }
        }
        return maxSum;
    }
};