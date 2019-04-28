class ListNode():
    """
    constructor to initiate this object
    """

    def __init__(self, item):
        self.item = item
        self.next = None

    def __str__(self):
        return str(self.item)

    def has_value(self, value):
        return self.item == value


class SingleLinkedList():
    def __init__(self):
        self._head = None

    def is_empty(self):
        return self._head is None

    def add(self, item):
        if not isinstance(item, ListNode):
            node = ListNode(item)
        else:
            node = item
        node.next = self._head
        self._head = node

    def length(self):
        current_node = self._head
        count = 0
        while current_node:
            count += 1
            current_node = current_node.next
        return count

    def append(self, item):
        if not isinstance(item, ListNode):
            node = ListNode(item)
        else:
            node = item
        if self.is_empty():
            self._head = node
        else:
            current_node = self._head
            while current_node.next:
                current_node = current_node.next
            current_node.next = node

    def travel(self):
        current_node = self._head
        while current_node:
            print(str(current_node.item)+"->", end="")
            current_node = current_node.next
        else:
            print("None")

    def insert(self, postion, item):
        if postion <= 0:
            self.add(item)
        elif postion > self.length()-1:
            self.append(item)
        else:
            node = ListNode(item)
            current_node = self._head
            current_postion = 0
            while current_node.next:
                if postion-1 == current_postion:
                    node.next = current_node.next
                    current_node.next = node
                current_node = current_node.next
                current_postion += 1

    def remove(self, item):
        current_node = self._head
        while current_node:
            if current_node.next.item == item:
                current_node.next = current_node.next.next
                break
            current_node = current_node.next

    def search(self, item):
        current_node = self._head
        count = 0
        while current_node:
            if current_node.item == item:
                return count
            current_node = current_node.next
            count += 1
        if count == self.length():
            count = -1
        return count


if __name__ == "__main__":
    sl = SingleLinkedList()
    sl.travel()
    print(sl.length())
    sl.add(1)
    sl.travel()
    sl.add(2)
    sl.travel()
    sl.append(65)
    sl.travel()
    print(sl.length())
    sl.insert(2,45)
    sl.travel()
    sl.remove(1)
    sl.search(2)
    sl.travel()
