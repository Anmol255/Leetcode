class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        # Ensure nums1 is the smaller array to optimize binary search runtime
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
            
        m, n = len(nums1), len(nums2)
        low, high = 0, m
        total_left = (m + n + 1) // 2
        
        while low <= high:
            partition1 = (low + high) // 2
            partition2 = total_left - partition1
            
            # Identify border elements, handling out-of-bound edges with infinity
            max_left1 = float('-inf') if partition1 == 0 else nums1[partition1 - 1]
            min_right1 = float('inf') if partition1 == m else nums1[partition1]
            
            max_left2 = float('-inf') if partition2 == 0 else nums2[partition2 - 1]
            min_right2 = float('inf') if partition2 == n else nums2[partition2]
            
            # Check if we found the correct partition alignment
            if max_left1 <= min_right2 and max_left2 <= min_right1:
                # Odd total number of elements
                if (m + n) % 2 == 1:
                    return float(max(max_left1, max_left2))
                # Even total number of elements
                return (max(max_left1, max_left2) + min(min_right1, min_right2)) / 2.0
            
            # Adjust binary search bounds
            elif max_left1 > min_right2:
                high = partition1 - 1
            else:
                low = partition1 + 1
                
        return 0.0

        

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna