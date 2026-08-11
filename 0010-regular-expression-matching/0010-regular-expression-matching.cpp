#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int m = s.length();
        int n = p.length();
        
        // dp[i][j] will be true if s[i...] matches p[j...]
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
        
        // Base case: empty string matches empty pattern
        dp[m][n] = true;
        
        // Fill the DP table from right to left
        for (int i = m; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                // Check if the current characters match
                bool first_match = (i < m) && (p[j] == s[i] || p[j] == '.');
                
                // Case 1: The next character is '*'
                if (j + 1 < n && p[j + 1] == '*') {
                    // dp[i][j+2] handles matching 0 occurrences of the character
                    // (first_match && dp[i+1][j]) handles matching 1 or more occurrences
                    dp[i][j] = dp[i][j + 2] || (first_match && dp[i + 1][j]);
                } 
                // Case 2: The next character is NOT '*'
                else {
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                }
            }
        }
        
        return dp[0][0];
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna