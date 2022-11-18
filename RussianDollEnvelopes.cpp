// Time Complexity : O(n * log n)
// Space Complexity : O(n)
// Did this code successfully run on Leetcode : yes


// Your code here along with comments explaining your approach
/* Convert problem to longest subsequence by sorting ascending order on first parameter and descending on second parameter (to handle conrner case of equal widths). 
 * Create a dp array to store the increasing subsequence. Maintain len variable to maintain length of sequence.
 * If current element is greater than the last dp element then simply add the current element in dp list and increase size of dp list.
 * Else find the largest element in the dp list by using binary search and replace that value with current nums value.
 * 
 * Note : This solution only return the correct size, not the correct sequence.
 */

class Solution {
public:
    int binarySearch(vector<int>& num, int target, int low, int high)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (target == num[mid])
            {
                return mid;
            }

            if (target < num[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b){
            if (a[0] == b[0])
            {
                return a[1] > b[1];
            }

            return a[0] < b[0];
        });

        int len = 1;
        vector<int> dp(envelopes.size(), 1);
        dp[0] = envelopes[0][1];

        for (int i = 1; i < envelopes.size(); i++)
        {
            if (dp[len - 1] < envelopes[i][1])
            {
                dp[len] = envelopes[i][1];
                len++;
            }
            else
            {
                int idx = binarySearch(dp, envelopes[i][1], 0, len - 1);
                dp[idx] = envelopes[i][1]; 
            }
        }
        return len;
    }
};
