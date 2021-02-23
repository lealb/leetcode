#include <iostream>
#include <vector>

using namespace std;
/**
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
    /**
     * @brief Create a List object
     * 
     * @param head 
     */
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
    /**
     * @brief Print ListNode object
     * 
     * @param head 
     */
    void printListNode(ListNode *head)
    {
        ListNode *phead = head;
        while (phead != NULL)
        {
            cout << phead->val << "->";
            phead = phead->next;
        }
        cout << "null\n";
    }
    /**
     * @brief 递归合并
     * 
     * @param l1 
     * @param l2 
     * @return ListNode* 
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
        {
            return l2;
        }
        if (!l2)
        {
            return l1;
        }
        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

    /**
     * @brief 非递归
     * 
     * @param l1 
     * @param l2 
     * @return ListNode* 
     */
    ListNode *mergeTwoLists_1(ListNode *l1, ListNode *l2)
    {
        ListNode *l = new ListNode(0);
        ListNode *ans = l;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                l->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else
            {
                l->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            l = l->next;
        }
        while (l1)
        {
            l->next = new ListNode(l1->val);
            l1 = l1->next;
            l = l->next;
        }
        while (l2)
        {
            l->next = new ListNode(l2->val);
            l2 = l2->next;
            l = l->next;
        }
        return ans->next;
    }
    ListNode *mergeTwoLists_2(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode *res = NULL;
        if (l1->val < l2->val)
        {
            res = l1;
            l1 = l1->next;
        }
        else
        {
            res = l2;
            l2 = l2->next;
        }
        ListNode *root = res;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                res->next = l1;
                l1 = l1->next;
            }
            else
            {
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
        }
        if (l1 != NULL)
            res->next = l1;
        else if (l2 != NULL)
            res->next = l2;
        return root;
    }
    ListNode *mergeTwoLists_3(ListNode *l1, ListNode *l2)
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
};
int main(int argc, char const *argv[])
{
    Solution solution;
    auto list1 = solution.generateListNode({1, 1, 6});
    auto list2 = solution.generateListNode({2, 3, 6, 8, 9});
    solution.printListNode(solution.mergeTwoLists_3(list1, list2));
    return 0;
}
