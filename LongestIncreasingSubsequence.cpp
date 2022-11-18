// Time Complexity : O(n * log n)
// Space Complexity : O(n)
// Did this code successfully run on Leetcode : yes


// Your code here along with comments explaining your approach
/* Create a dp array to store the increasing subsequence. Maintain len variable to maintain length of sequence.
 * If current nums element is greater than the last dp element then simply add the current element in dp list and increase size of dp list.
 * Else find the largest element in the dp list by using binary search and replace that value with current nums value.
 * 
 * Note : This solution only return the correct size, not the correct sequence.
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

