# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        """
            简化版代码，使用divmod处理 tuple (x//y, x%y)
        """
        pre_node = ListNode(0)
        last_node = pre_node
        # 进位标志
        carry = 0
        # carry 一起加入循环判断，当最高位进位的时候，恰好为1
        while carry or l1 or l2:
            carry, current_value = divmod(carry + (l1.val if l1 else 0) +
                                          (l2.val if l2 else 0), 10)
            last_node.next = ListNode(current_value)
            last_node = last_node.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        return pre_node.next

    def addTwoNumbers_1(self, l1: ListNode, l2: ListNode) -> ListNode:
        # 头结点
        dummy_head = ListNode(0)
        # 当前结点初始化为头结点
        curr = dummy_head
        # 进位标志
        carry = 0
        while carry or l1 or l2:
            sum = carry+(l1.val if l1 else 0)+(l2.val if l2 else 0)
            carry = sum//10
            curr.next = ListNode(sum % 10)
            curr = curr.next
            # list node 指针移动，类似循环中的i++
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        return dummy_head.next


def generateList(l: list) -> ListNode:
    prenode = ListNode(0)
    lastnode = prenode
    for val in l:
        lastnode.next = ListNode(val)
        lastnode = lastnode.next
    return prenode.next


def printList(l: ListNode):
    while l:
        print("%d->" % (l.val), end='')
        l = l.next
    print('')


if __name__ == "__main__":
    l1 = generateList([1, 5, 8])
    l2 = generateList([9, 1, 2, 9])
    printList(l1)
    printList(l2)
    s = Solution()
    sum = s.addTwoNumbers(l1, l2)
    printList(sum)
    printList(s.addTwoNumbers_1(l1, l2))
