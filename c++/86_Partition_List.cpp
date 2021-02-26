#include <iostream>
#include <vector>
#include "listnode.h"
using namespace std;
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        //小链表的头、尾
        ListNode *smallHead = new ListNode(0), *smallTail = smallHead;
        //大链表的头、尾
        ListNode *bigHead = new ListNode(0), *bigTail = bigHead;
        while (head)
        {
            //如果当前节点的值小于x，则把当前节点挂到小链表的后面
            head->val < x ? smallTail = smallTail->next = head : bigTail = bigTail->next = head;
            //继续循环下一个结点
            head = head->next;
        }
        //最后再把大小链表拼接在一块即可
        smallTail->next = bigHead->next;
        bigTail->next = nullptr;
        return smallHead->next;
    }
    /**
     * @brief Two Pointers
     * 
     * @param head 
     * @param x 
     * @return ListNode* 
     */
    ListNode *partition_1(ListNode *head, int x)
    {
        if (!head)
        {
            return nullptr;
        }
        ListNode *p = new ListNode(0), *slow = p, *fast = head->next;
        slow->next = head;
        while (fast)
        {
            if (slow->next->val < x)
            {
                slow = slow->next;
                head = fast;
            }
            else if (fast->val < x)
            {
                head->next = fast->next;
                fast->next = slow->next;
                slow = slow->next = fast;
            }
            else
                head = fast;
            fast = head->next;
        }
        return p->next;
    }

    /**
     * @brief Fiber
     * 
     * @param head 
     * @param x 
     * @return ListNode* 
     */
    ListNode *partition_2(ListNode *head, int x)
    {
        ListNode *p = new ListNode(0), *prev = p;
        ListNode *pTag = new ListNode(0), *tag = pTag;
        prev->next = head;
        while (head)
        {
            if (head->val >= x)
            {
                prev->next = head->next;
                tag = tag->next = head;
            }
            else
            {
                prev = head;
            }
            head = head->next;
        }
        tag->next = nullptr;
        prev->next = pTag->next;
        return p->next;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    ListNode *list = generateListNode({2, 6, 3, 7, 4, 10});
    printListNode(solution.partition_2(list, 5));
    system("pause");
    return 0;
}
