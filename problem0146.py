class Node:
    def __init__(self, value: int, next = None, prev = None):
        self.value = value
        self.next = next
        self.prev = prev

class DLL:
    def __init__(self):
        self.head = None

    def insertFirst(self, node: Node, removeLast = False):
        if self.head:
            node.next = self.head
            node.prev = self.head.prev
            self.head.prev = node
            self.head = node
        else:
            self.head = node
            node.next = node
            node.prev = node

class LRUCache:

    def __init__(self, capacity: int):
        self.hashtable = {}
        self.dll = DLL()
        self.capacity = capacity
        self.count = 0
        pass

    def get(self, key: int) -> int:
        if self.hashtable[key]:
            return self.hashtable[key].value
        else:
            return None
        pass

    def put(self, key: int, value: int) -> None:
        node = self.hashtable[key]
        if node:
            node.value = value
            node = self.dll.remove(node)
            self.dll.insertFirst(node)
        else:
            if self.count < self.capacity:
                self.hashtable[key] = value
                node = Node(value)
                self.dll.insertFirst(node)
            else:

