class Solution {
public:
    bool isPalindrome(int x) {
        // Edge cases:
        // 1. Negative numbers are not palindromes (e.g., -121 reads as 121-).
        // 2. Numbers ending in 0 are not palindromes (except 0 itself) because 
        //    a multi-digit number cannot start with 0.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        
        // Keep stripping digits from the end of x and adding them to reversedHalf
        // until we reach the middle of the number.
        while (x > reversedHalf) {
            reversedHalf = (reversedHalf * 10) + (x % 10);
            x /= 10;
        }

        // For even-length numbers (e.g., 1221): x will be 12, reversedHalf will be 12. -> x == reversedHalf
        // For odd-length numbers (e.g., 12321): x will be 12, reversedHalf will be 123.
        // We can get rid of the middle digit by doing reversedHalf / 10.
        return x == reversedHalf || x == reversedHalf / 10;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna