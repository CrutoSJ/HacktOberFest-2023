#include <iostream>
#include <vector>

int lengthOfLIS(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        maxLen = std::max(maxLen, dp[i]);
    }

    return maxLen;
}

int main() {
    std::vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int length = lengthOfLIS(nums);
    std::cout << "Length of the Longest Increasing Subsequence: " << length << std::endl;
    return 0;
}
