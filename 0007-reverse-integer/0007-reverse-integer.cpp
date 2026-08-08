#include <climits> // Needed for INT_MAX and INT_MIN

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            
            // Check for overflow before multiplying res by 10
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && pop > 7)) return 0;
            
            // Check for underflow before multiplying res by 10
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && pop < -8)) return 0;
            
            res = res * 10 + pop;
        }
        
        return res;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna