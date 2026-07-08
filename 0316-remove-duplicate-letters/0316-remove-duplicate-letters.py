class Solution:
    def removeDuplicateLetters(self, s):
        count = {}        # remaining count of each character
        in_stack = {}     # whether character is already in stack
        stack = []

        # Count frequency of each character
        for c in s:
            count[c] = count.get(c, 0) + 1

        for c in s:
            count[c] -= 1  # one less occurrence remaining

            if in_stack.get(c):
                continue   # already in result, skip

            # Pop larger characters if they appear later in string
            while stack and c < stack[-1] and count[stack[-1]] > 0:
                in_stack[stack.pop()] = False

            stack.append(c)
            in_stack[c] = True

        return "".join(stack)
        