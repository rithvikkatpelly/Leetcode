"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node):
        if node is None:
            return None
        
        visited = {}
        
        def dfs(original):
            if original in visited:
                return visited[original]
            
            copy = Node(original.val)
            visited[original] = copy
            
            for neighbor in original.neighbors:
                copy.neighbors.append(dfs(neighbor))
            
            return copy
        
        return dfs(node)