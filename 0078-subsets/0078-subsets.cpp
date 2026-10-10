
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        auto dfs = [&](auto&& self, int idx) -> void {
            ans.push_back(curr);

            for (int i = idx; i < nums.size(); ++i) {
                curr.push_back(nums[i]);
                self(self, i + 1);
                curr.pop_back();
            }
        };

        dfs(dfs, 0);
        return ans;
    }
};
