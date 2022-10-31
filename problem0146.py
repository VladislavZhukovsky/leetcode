class Node:
    def __init__(self, key: int, value: int, next = None, prev = None):
        self.key = key
        self.value = value
        self.next = next
        self.prev = prev

class DLL:
    def __init__(self):
        self.head = None

    def insertFirst(self, node: Node, removeLast = False):
        if self.head:
            if removeLast:
                nodeLast = self.head.prev
                node.next = self.head#I
                self.head.prev = node#II
                node.prev = nodeLast.prev #III
                nodeLast.prev.next = node
                self.head = node
                return nodeLast
            else:
                nodeLast = self.head.prev
                node.next = self.head
                self.head.prev = node
                node.prev = nodeLast
                nodeLast.next = node
                self.head = node
        else:
            node.next = node
            node.prev = node
            self.head = node


    def move(self, node: Node):
        if node is self.head:
            return
        if node is self.head.prev:
            self.head = node
            return
        node.next.prev = node.prev
        node.prev.next = node.next
        self.insertFirst(node, False)

class LRUCache:
    def __init__(self, capacity: int):
        self.hashtable = {}
        self.dll = DLL()
        self.capacity = capacity
        self.count = 0
        pass

    def get(self, key: int) -> int:
        node = self.hashtable.get(key)
        if node:
            self.dll.move(node)
            return node.value
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        node = self.hashtable.get(key)
        if node:
            node.value = value
            self.dll.move(node)
        else:
            node = Node(key, value)
            self.hashtable[key] = node
            if self.count < self.capacity:
                self.dll.insertFirst(node, False)   
            else:
                nodeLast = self.dll.insertFirst(node, True)
                self.hashtable.pop(nodeLast.key)
            self.count = self.count + 1
        

lRUCache = LRUCache(2)
lRUCache.put(1, 1)
lRUCache.put(2, 2)
print(lRUCache.get(1))
lRUCache.put(3, 3)
print(lRUCache.get(2))
lRUCache.put(4, 4)
print(lRUCache.get(1))
print(lRUCache.get(3))
print(lRUCache.get(4))