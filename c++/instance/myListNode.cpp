#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Definde ListNode
 * 
 */
struct ListNode
{
    int val;
    ListNode *next;
    // ListNode(val)
    // node->val=val;
    //node->next=null;
    ListNode(int x) : val(x), next(nullptr) {}
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
     * @brief add
     *  1.判断原链表是否是空链表，如果是，将head指向新增结点
     *  2.如果不是空链表，向链表尾部插入新结点
     * @param head 
     * @param val 
     * @return ListNode* 
     */
    ListNode *addListNode(ListNode *head, int val)
    {
        ListNode *newNode = new ListNode(val);
        ListNode *p = head;
        if (p == nullptr)
        {
            head = newNode;
        }
        else
        {
            while (p->next != nullptr)
            {
                p = p->next;
            }
            p->next = newNode;
        }
        return head;
    }

    ListNode *insertListNodeByPos(ListNode *head, int i, int val)
    {
        ListNode *p = head;
        int j = 0;
        // find insert position
        while (p && j < i - 1)
        {
            p = p->next;
            j++;
        }
        if (!p || j > i - 1)
        {
            cout << "Insert position is invaild" << endl;
        }
        else
        {
            ListNode *insertNode = new ListNode(val);
            insertNode->next = p->next;
            p->next = insertNode;
        }
        return head;
    }

    /**
     * @brief 反转列表
     * 
     * @param head 
     * @return ListNode* 
     */
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *temp;
        while (cur != NULL)
        {
            temp = cur->next; //temp存放当前结点的下一结点的地址
            cur->next = pre;  //当前结点指向前一个结点
            pre = cur;        //pre往前走一个结点
            cur = temp;       //cur也走到下一个结点
        }
        return pre; //最后pre走到正向的最后一个结点，即反向链表的第一个结点，所以返回pre
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *pPrev = nullptr;
        ListNode *p = head;
        ListNode *pReverseHead = nullptr;
        while (p != nullptr)
        {
            ListNode *pNext = p->next;
            if (pNext == nullptr)
            {
                pReverseHead = p;
            }
            p->next = pPrev;
            pPrev = p;
            p = pNext;
        }
        return pReverseHead;
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
     * @brief merge sorted list 
     * 
     * @param l1 
     * @param l2 
     * @return ListNode* 
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
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

    ListNode *mergeSortList(ListNode *l1, ListNode *l2)
    {
        if (!l1 || !l2)
        {
            if (!l1)
            {
                return l2;
            }
            else if (!l2)
            {
                return l1;
            }
            else
            {
                return nullptr;
            }
        }
        ListNode *tempHead = nullptr;
        // get head
        if (l1->val > l2->val)
        {
            tempHead = l2;
            l2 = l2->next;
        }
        else
        {
            tempHead = l1;
            l1 = l1->next;
        }
        ListNode *l3 = tempHead;
        while (l1 && l2)
        {
            // get head
            if (l1->val > l2->val)
            {
                l3->next = l2;
                l2 = l2->next;
            }
            else
            {
                l3->next = l1;
                l1 = l1->next;
            }
        }
        // 处理未比较节点
        if (l1)
        {
            l3->next = l1;
        }
        if (l2)
        {
            l3->next = l2;
        }
        return l3;
    }
};

int main()
{
    Solution solution;
    auto list1 = solution.generateListNode({1, 1, 6});
    auto list2 = solution.generateListNode({2, 3, 6, 8, 9});
    // solution.printListNode(list1);
    // //add
    // solution.printListNode(solution.addListNode(list1, 2));
    // //insert
    // solution.printListNode(solution.insertListNodeByPos(list1, 3, 120));
    // solution.printListNode(solution.reverseList(list1));
    // solution.printListNode(list2);
    // solution.printListNode(solution.reverse(list2));

    //merge
    solution.printListNode(solution.mergeTwoLists(list1, list2));
    return 0;
}