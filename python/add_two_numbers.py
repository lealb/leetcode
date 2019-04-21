# leetcode
class ListNode():
    def __init__(self, x):
        self.val = x
        self.next = None

    def add(self, value):
        head = ListNode(value)
        head.next=None
        return head

    def get_list(self, node):
        while node:
            print(str(node.val)+"->",end="")
            node = node.next

    def addTwoNumbers(self, l1, l2):
        pass


if __name__ == "__main__":
    list_node = ListNode(0)
    data=[1,4,6]
    for i in data:
        node = list_node.add(i)
    list_node.get_list(node)
  
