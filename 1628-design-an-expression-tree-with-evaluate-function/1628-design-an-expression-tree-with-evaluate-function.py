"""
This is the interface for the expression tree Node.
You should not remove it, but you can modify it as needed.
"""
class Node:
    def evaluate(self) -> int:
        pass

    def build_tree(self, postfix: List[str]) -> 'Node':
        pass


OPERATORS = {
    '+': lambda a, b: a + b,
    '-': lambda a, b: a - b,
    '*': lambda a, b: a * b,
    '/': lambda a, b: int(a / b),  # truncate toward zero
}


class OperandNode(Node):
    def __init__(self, val: int):
        self.val = val

    def evaluate(self) -> int:
        return self.val


class OperatorNode(Node):
    def __init__(self, op: str, left: Node, right: Node):
        self.op = op
        self.left = left
        self.right = right

    def evaluate(self) -> int:
        return OPERATORS[self.op](self.left.evaluate(), self.right.evaluate())


class TreeBuilder:
    def buildTree(self, postfix: List[str]) -> 'Node':
        stack = []
        for token in postfix:
            if token in OPERATORS:
                right = stack.pop()
                left = stack.pop()
                stack.append(OperatorNode(token, left, right))
            else:
                stack.append(OperandNode(int(token)))
        return stack[-1]