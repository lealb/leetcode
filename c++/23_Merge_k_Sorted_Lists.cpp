#include <iostream>
#include <vector>
#include <queue>
#include "listnode.h"
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(-3);
        ListNode *tail = &dummy;
        while (l1 and l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }

    ListNode *mergeKLists_1(vector<ListNode *> &lists)
    {
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> minHeap;
        for (ListNode *&head : lists)
        {
            if (head)
            {
                minHeap.push({head->val, head});
            }
        }
        ListNode *root = new ListNode();
        ListNode *walk = root;
        while (!minHeap.empty())
        {
            // Get the minimum element from the heap
            pair<int, ListNode *> cur = minHeap.top();
            minHeap.pop();

            // Add the minimum element to the result
            walk->next = new ListNode(cur.second->val);
            walk = walk->next;

            // Update the pointer and push it back to minHeap
            if (cur.second->next)
            {
                minHeap.push({cur.second->next->val, cur.second->next});
            }
        }
        return root->next;
    }
    /**
     * @brief 二分法
     * 
     * @param lists 
     * @return ListNode* 
     */
    ListNode *mergeKLists_2(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        int size = lists.size();
        while (size > 1)
        {
            for (int i = 0; i < size; i += 2)
            {
                ListNode *l1 = lists[i];
                ListNode *l2 = i + 1 < size ? lists[i + 1] : nullptr;
                lists[i / 2] = mergeTwoLists(l1, l2);
            }
            size = (size + 1) / 2;
        }
        return lists.front();
    }
    ListNode *mergeKLists_3(vector<ListNode *> &lists)
    {

        if (lists.size() == 0)
            return NULL;

        int last = lists.size() - 1;

        while (last != 0)
        {
            int i = 0;
            int j = last;

            while (i < j)
            {
                lists[i] = mergeTwoLists(lists[i], lists[j]);
                i++;
                j--;

                if (i >= j)
                {
                    last = j;
                }
            }
        }

        return lists[0];
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    //get test data
    vector<ListNode *> lists = {generateListNode({1, 4, 5}), generateListNode({2, 6, 9}), generateListNode({2, 4, 8})};
    printListNode(solution.mergeKLists_2(lists));
    system("pause");
    return 0;
}
