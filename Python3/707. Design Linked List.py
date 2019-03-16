class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class MyLinkedList:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head = None
        self.size = 0

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        if index < 0 or index >= self.size:
            return -1
        else:
            cur = self.head
            while index > 0:
                cur = cur.next
                index -= 1
            return cur.val

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        new = ListNode(val)
        self.head, new.next = new, self.head
        self.size += 1

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        new = ListNode(val)
        if self.head is None:
            self.head = new
        else:
            cur = self.head
            while cur and cur.next:
                cur = cur.next
            cur.next = new
        self.size += 1

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if index < 0 or index > self.size:
            return
        else:
            new = ListNode(val)
            prev, cur = None, self.head
            for _ in range(index):
                prev, cur = cur, cur.next
            if prev is None:
                self.head, new.next = new, self.head
            else:
                prev.next, new.next = new, prev.next
            self.size += 1

    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if index < 0 or index >= self.size:
            return
        else:
            if index == 0:
                self.head = self.head.next
            else:
                prev, cur = None, self.head
                for _ in range(index):
                    prev, cur = cur, cur.next
                prev.next = cur.next
            self.size -= 1

# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)