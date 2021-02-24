#include <iostream>
#include <vector>
#include "listnode.h"
using namespace std;
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *currNode = head;
        while (currNode && currNode->next)
        {
            // 位运算交换相邻列表元素
            currNode->val ^= currNode->next->val;
            currNode->next->val ^= currNode->val;
            currNode->val ^= currNode->next->val;
            //连接交换后的元素
            currNode = currNode->next->next;
        }
        return head;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    ListNode *list = generateListNode({2, 4, 6, 7, 8, 9, 10});
    printListNode(solution.swapPairs(list));
    system("pause");
    return 0;
}
