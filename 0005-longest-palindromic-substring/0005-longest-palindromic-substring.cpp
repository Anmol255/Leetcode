#include <string>
#include <algorithm>
#include <iostream>

class Solution {
private:
    // Helper function to expand around center and return the length
    int expandAroundCenter(const std::string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }

public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int maxLen = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // Odd length palindromes (e.g., "aba")
            int len1 = expandAroundCenter(s, i, i);
            // Even length palindromes (e.g., "abba")
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int currentLen = std::max(len1, len2);
            
            if (currentLen > maxLen) {
                maxLen = currentLen;
                start = i - (currentLen - 1) / 2;
            }
        }
        
        return s.substr(start, maxLen);
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna