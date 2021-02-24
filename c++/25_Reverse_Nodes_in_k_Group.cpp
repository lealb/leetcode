#include <iostream>
#include <vector>
#include "listnode.h"
using namespace std;
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *temp;
        while (cur)
        {
            temp = cur->next; //temp存放当前结点的下一结点的地址
            cur->next = pre;  //当前结点指向前一个结点
            pre = cur;        //pre往前走一个结点
            cur = temp;       //cur也走到下一个结点
        }
        return pre; //最后pre走到正向的最后一个结点，即反向链表的第一个结点，所以返回pre
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *u = head;
        //get listnode counts
        int count = 0;
        while (u)
        {
            count++;
            u = u->next;
        }
        ListNode *s = head;
        ListNode *dummy2 = new ListNode();
        dummy2->next = head;
        ListNode *t = dummy2;
        ListNode *pv;
        int n;
        while (s)
        {
            n = k;
            ListNode *dummy = new ListNode();
            pv = s;
            while (n-- && s)
            {
                ListNode *temp = dummy->next;
                dummy->next = s;
                s = s->next;
                dummy->next->next = temp;
                count--;
            }
            t->next = dummy->next;
            t = pv;
            if (count < k)
            {
                //dummy2->next->next=s;
                t->next = s;
                return dummy2->next;
            }
        }
        return dummy2->next;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    ListNode *list = generateListNode({1, 4, 5, 7, 8, 10, 12});
    printListNode(solution.reverseList(list));
    system("pause");
    return 0;
}
