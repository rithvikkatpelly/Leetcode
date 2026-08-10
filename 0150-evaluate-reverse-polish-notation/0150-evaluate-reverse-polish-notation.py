class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        ops = {'+', '-', '*', '/'}
        
        for tok in tokens:
            if tok in ops:
                b = stack.pop()
                a = stack.pop()
                if tok == '+':
                    stack.append(a + b)
                elif tok == '-':
                    stack.append(a - b)
                elif tok == '*':
                    stack.append(a * b)
                else:
                    # truncate toward zero
                    stack.append(int(a / b))
            else:
                stack.append(int(tok))
        
        return stack[0]     