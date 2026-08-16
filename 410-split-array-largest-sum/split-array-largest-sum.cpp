class Solution {
private:
    bool isPossible(vector<int>& nums, int k, int maxPages) {
        int studentCount = 1;
        int pages = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxPages) {
                return false;
            }

            if (pages + nums[i] > maxPages) {
                studentCount++;
                pages = nums[i];

                if (studentCount > k) {
                    return false;
                }
            } else {
                pages += nums[i];
            }
        }
        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        if (k > nums.size()) {
            return -1;
        }

        int sum = 0;
        int maxVal = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxVal = max(maxVal, nums[i]);
        }

        int st = maxVal;
        int end = sum;
        int ans = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (isPossible(nums, k, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return ans;
    }
};
