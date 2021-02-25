#include <iostream>
#include <vector>
#include "listnode.h"
using namespace std;
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *temp = head;
        // 虚拟节点
        ListNode *prev = new ListNode(0);
        while (temp && temp->next)
        {
            if (temp->val == temp->next->val)
            {
                // 连续相同，指针移动
                while (temp->next && temp->val == temp->next->val)
                {
                    temp->next = temp->next->next;
                }
                // 头结点为相同元素
                if (temp == head)
                {
                    head = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                    temp = temp->next;
                }
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    ListNode *list = generateListNode({1, 1, 2, 3, 4, 4});
    printListNode(solution.deleteDuplicates(list));
    system("pause");
    return 0;
}
