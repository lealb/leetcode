#include <iostream>
#include <vector>
using namespace std;

/**
 *  回头调试一下，好好理解
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *generateListNode(vector<int> vals)
    {
        ListNode *res = nullptr;
        ListNode *last = nullptr;
        for (auto val : vals)
        {
            if (last)
            {
                last->next = new ListNode(val);
                last = last->next;
            }
            else
            {
                res = new ListNode(val);
                last = res;
            }
        }
        return res;
    }

    void freeListNode(ListNode *head)
    {
        ListNode *node = head;
        while (node)
        {
            auto temp = node->next;
            delete node;
            node = temp;
        }
    }

    /**
     * print list node
     */
    void printListNode(ListNode *head)
    {
        ListNode *node = head;
        while (node)
        {
            cout << node->val << "->";
            node = node->next;
        }
        cout << "null" << endl;
    }
    /**
     * Time complexity : O(L)
     * The algorithm makes two traversal of the list, 
     * first to calculate list length L and second to find the (L - n) th node. 
     * There are 2L-n2L−n operations and time complexity is O(L).
     * Space complexity : O(1).
     * we only used constant extra space.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        int length = 0;
        ListNode *first = head;
        while (first != NULL)
        {
            length++;
            first = first->next;
        }
        cout << "L: " << length << endl;
        length -= n;
        first = dummy;
        while (length > 0)
        {
            length--;
            first = first->next;
        }
        first->next = first->next->next;
        return dummy->next;
    }

    /**
     * Approach 2: One pass algorithm
     * Time complexity : O(L).
     * The algorithm makes one traversal of the list of L nodes.
     *  Therefore time complexity is O(L).
     * Space complexity : O(1).
     * We only used constant extra space.
     */
    ListNode *removeNthFromEnd_1(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *first = dummy;
        ListNode *second = dummy;
        // Advances first pointer so that the gap between first and second is n nodes apart
        for (int i = 1; i <= n + 1; i++)
        {
            first = first->next;
        }
        // Move first to the end, maintaining the gap
        while (first != NULL)
        {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    auto list = solution.generateListNode({1, 2, 3, 4, 5});
    solution.printListNode(list);
    solution.printListNode(solution.removeNthFromEnd_1(list, 4));
    return 0;
}
