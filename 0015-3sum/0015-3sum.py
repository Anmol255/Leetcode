class Solution:
    def threeSum(self, nums):
        res = []
        nums.sort()
        
        for i in range(len(nums)):
            # Agar sabse chota number hi 0 se bada hai, toh sum 0 nahi ho sakta
            if nums[i] > 0:
                break
                
            # Pehle element ke duplicates skip karne ke liye
            if i > 0 and nums[i] == nums[i - 1]:
                continue
                
            left, right = i + 1, len(nums) - 1
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                
                if total == 0:
                    res.append([nums[i], nums[left], nums[right]])
                    left += 1
                    right -= 1
                    
                    # Doosre element ke duplicates skip karne ke liye
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                    # Teesre element ke duplicates skip karne ke liye
                    while left < right and nums[right] == nums[right + 1]:
                        right -= 1
                        
                elif total < 0:
                    left += 1
                else:
                    right -= 1
                    
        return res


# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna