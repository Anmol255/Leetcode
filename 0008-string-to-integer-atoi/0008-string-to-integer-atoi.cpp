#include <string>
#include <climits>
#include <cctype> // Required for std::isdigit

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        int result = 0;

        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check for optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Convert characters and handle overflow
        // FIXED: Replaced s[i] <= '10' with std::isdigit()
        while (i < n && std::isdigit(s[i])) { 
            int digit = s[i] - '0';

            // Check overflow before updating result
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna