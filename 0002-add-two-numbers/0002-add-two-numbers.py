class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # Initialize a dummy head to easily construct the result list
        dummy = ListNode(0)
        current = dummy
        carry = 0
        
        # Loop while there are nodes to process or a carry remains
        while l1 or l2 or carry:
            # Extract values, defaulting to 0 if the list has ended
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            
            # Calculate total sum and update the carry
            total = val1 + val2 + carry
            carry = total // 10
            
            # Create a new node with the single-digit result
            current.next = ListNode(total % 10)
            current = current.next
            
            # Advance to the next nodes if they exist
            if l1: l1 = l1.next
            if l2: l2 = l2.next
            
        return dummy.next

        

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna