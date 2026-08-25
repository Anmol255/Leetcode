class Solution(object):
    def letterCombinations(self, digits):
        if not digits:
            return []
        
        # Map digits to letters
        phone_map = {
            "2": "abc", "3": "def", "4": "ghi", "5": "jkl",
            "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"
        }
        
        result = []
        
        def backtrack(index, current_path):
            # Base case: if path length equals digits length
            if index == len(digits):
                result.append(current_path)
                return
            
            # Get letters for the current digit and recurse
            current_digit = digits[index]
            for letter in phone_map[current_digit]:
                backtrack(index + 1, current_path + letter)
                
        backtrack(0, "")
        return result


# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna