class MyNode:
    def __init__(self, val, prev = None, next = None):
        self.val = val
        self.prev = prev
        self.next = next
        

class MyLinkedList:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head = MyNode(float('-inf'))
        self.tail = MyNode(float('inf'))
        self.head.next, self.tail.prev = self.tail, self.head
        self.len = 0
        
    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        if index >= self.len:
            return -1
        tmp = self.head.next
        for _ in range(index):
            tmp = tmp.next
        return tmp.val
        
    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        newHead = MyNode(val, self.head, self.head.next)
        self.head.next.prev, self.head.next = newHead, newHead
        self.len += 1

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        newTail = MyNode(val, self.tail.prev, self.tail)
        self.tail.prev.next, self.tail.prev = newTail, newTail
        self.len += 1
        

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if index == self.len:
            self.addAtTail(val)
        elif 0 <= index < self.len:
            tmp = self.head
            for _ in range(index):
                tmp = tmp.next
            newNode = MyNode(val, tmp, tmp.next)
            tmp.next.prev, tmp.next = newNode, newNode
            self.len += 1

    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if 0 <= index < self.len:
            tmp = self.head
            for _ in range(index):
                tmp = tmp.next
            tmp.next.next.prev, tmp.next = tmp, tmp.next.next
            self.len -= 1
        


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)