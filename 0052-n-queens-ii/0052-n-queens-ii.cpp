
class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        int mask = (1 << n) - 1;

        auto dfs = [&](auto&& self, int cols, int diag1, int diag2) -> void {
            if (cols == mask) {
                ++count;
                return;
            }

            int available = mask & ~(cols | diag1 | diag2);

            while (available) {
                int bit = available & -available;
                available -= bit;

                self(self,
                     cols | bit,
                     ((diag1 | bit) << 1) & mask,
                     (diag2 | bit) >> 1);
            }
        };

        dfs(dfs, 0, 0, 0);
        return count;
    }
};
