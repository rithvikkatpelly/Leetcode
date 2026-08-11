from typing import List
from collections import deque

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # Build adjacency list and in-degree count
        graph = [[] for _ in range(numCourses)]
        in_degree = [0] * numCourses

        for course, prereq in prerequisites:
            graph[prereq].append(course)
            in_degree[course] += 1

        # Start with all courses that have no prerequisites
        queue = deque([course for course in range(numCourses) if in_degree[course] == 0])
        order = []

        while queue:
            current = queue.popleft()
            order.append(current)

            for next_course in graph[current]:
                in_degree[next_course] -= 1
                if in_degree[next_course] == 0:
                    queue.append(next_course)

        # If we ordered all courses, return the order; otherwise there's a cycle
        return order if len(order) == numCourses else []
        