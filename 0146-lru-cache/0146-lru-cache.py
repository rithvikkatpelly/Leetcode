class Node:
    __slots__ = ('key', 'val', 'prev', 'next')

    def __init__(self, key=0, val=0):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None


class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}  # key -> Node

        # Dummy head/tail sentinels to avoid null checks
        # head.next is the most recently used, tail.prev is the least recently used
        self.head = Node()
        self.tail = Node()
        self.head.next = self.tail
        self.tail.prev = self.head

    def _remove(self, node: 'Node') -> None:
        """Unlink node from the list."""
        node.prev.next = node.next
        node.next.prev = node.prev

    def _add_to_front(self, node: 'Node') -> None:
        """Insert node right after head (marks it as most recently used)."""
        node.next = self.head.next
        node.prev = self.head
        self.head.next.prev = node
        self.head.next = node

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        node = self.cache[key]
        self._remove(node)
        self._add_to_front(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            node = self.cache[key]
            node.val = value
            self._remove(node)
            self._add_to_front(node)
        else:
            if len(self.cache) >= self.capacity:
                lru = self.tail.prev
                self._remove(lru)
                del self.cache[lru.key]

            node = Node(key, value)
            self.cache[key] = node
            self._add_to_front(node)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
# obj.put(key,value)