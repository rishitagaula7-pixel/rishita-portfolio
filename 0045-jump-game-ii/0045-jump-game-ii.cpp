class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        // If the array has 1 or fewer elements, 0 jumps are needed
        if (n <= 1) return 0;
        
        int jumps = 0;
        int current_end = 0;
        int farthest = 0;
        
        // Loop through the array, stopping before the last element
        for (int i = 0; i < n - 1; ++i) {
            // Track the furthest index reachable from current or previous positions
            farthest = std::max(farthest, i + nums[i]);
            
            // If we've reached the end of our current jump range
            if (i == current_end) {
                jumps++;
                current_end = farthest; // Set the new boundary
                
                // Early exit optimization if we can already reach the end
                if (current_end >= n - 1) {
                    break;
                }
            }
        }
        
        return jumps;
    }
};