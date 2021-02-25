#include <iostream>
#include <vector>
#include "listnode.h"
using namespace std;
class Solution
{
public:
    /**
     * @brief 
     * 先遍历求得链表总长度count，同时将链表首尾相连；
     * 再找到原链表的倒数第k+1个节点，该节点的next就是新链表的头结点
     * 
     * @param head 
     * @param k 
     * @return ListNode* 
     */
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || !k)
        {
            return head;
        }

        ListNode *last = head;
        int size = 1;
        while (last->next)
        {
            size++;
            last = last->next;
        }
        int n = k % size;
        if (!n)
        {
            return head;
        }
        //循环链表
        last->next = head;
        for (int i = 0; i < size - n; i++)
        {
            last = head;
            head = head->next;
        }
        //单链表
        last->next = NULL;
        // printListNode(last);
        return head;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    ListNode *list = generateListNode({1, 4, 5, 7, 8, 10, 12});
    printListNode(solution.rotateRight(list, 2));
    system("pause");
    return 0;
}
