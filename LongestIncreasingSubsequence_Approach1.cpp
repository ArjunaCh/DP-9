// Time Complexity : O(n * n)
// Space Complexity : O(n)
// Did this code successfully run on Leetcode : yes


// Your code here along with comments explaining your approach
/* Create a dp array to store the increasing subsequence. Initialize with 1.
 * Start iterating over the array. Use other pointer to iterate from 0 till current position.
 * If the element is smaller than current location then update the dp value as max of current and that value + 1.
 * At the end return max value.
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }   

        vector<int> dp(nums.size(), 1);
        int max = 1;
        for (int j = 1; j < nums.size(); j++)
        {
            for (int i = 0; i < j; i++)
            {
                if (nums[i] < nums[j])
                {
                    dp[j] = std::max(dp[j], dp[i] + 1);
                    max = std::max(max, dp[j]);
                }
            }
        }

        return max;
    }
};