class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::stack<int> st;
        // Push -1 as a base for calculating lengths
        st.push(-1);
        int max_len = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                // Store the index of the opening parenthesis
                st.push(i);
            } else {
                // Pop the last matching opening parenthesis or base index
                st.pop();
                
                if (st.empty()) {
                    // If empty, this ')' is unmatched; push its index as the new base
                    st.push(i);
                } else {
                    // Calculate length by subtracting the current index from the top of the stack
                    max_len = std::max(max_len, i - st.top());
                }
            }
        }
        
        return max_len;
    }
};