#include <iostream>
#include <vector>
#include "listnode.h"
using namespace std;
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *curr = head;
        while (curr && curr->next)
        {
            if (curr->next->val == curr->val)
            {
                curr->next = curr->next->next;
            }
            else
            {
                curr = curr->next;
            }
        }
        return head;
    }

    /**
     * @brief Two pointer
     * 
     * @param head 
     * @return ListNode* 
     */
    ListNode *deleteDuplicates_1(ListNode *head)
    {
        if (!head)
        {
            return NULL;
        }
        // fast=head->next
        ListNode *fast = head->next, *slow = head;
        while (fast)
        {
            if (slow->val != fast->val)
            {
                slow->next = fast;
                slow = slow->next;
            }
            fast = fast->next;
        }
        slow->next = nullptr;
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
