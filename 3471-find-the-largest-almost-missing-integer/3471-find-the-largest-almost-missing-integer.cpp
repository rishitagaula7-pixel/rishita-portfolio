#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int largestInteger(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        // Case 1: Only 1 subarray exists (the entire array)
        if (k == n) {
            return *std::max_element(nums.begin(), nums.end());
        }
        
        // Count the frequency of all elements globally
        std::unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        
        // Case 2: Subarrays of size 1
        if (k == 1) {
            int max_val = -1;
            for (const auto& [num, count] : counts) {
                if (count == 1) {
                    max_val = std::max(max_val, num);
                }
            }
            return max_val;
        }
        
        // Case 3: 1 < k < nums.length
        // Only the first or last element can appear in exactly one subarray
        int ans = -1;
        if (counts[nums[0]] == 1) {
            ans = std::max(ans, nums[0]);
        }
        if (counts[nums[n - 1]] == 1) {
            ans = std::max(ans, nums[n - 1]);
        }
        
        return ans;
    }
};
