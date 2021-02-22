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
};

int main()
{
    Solution solution;
    auto list1 = solution.generateListNode({1, 4, 6});
    auto list2 = solution.generateListNode({9, 4, 6, 9});
    solution.printListNode(list1);
    solution.printListNode(solution.reverseList(list1));
    solution.printListNode(list2);
    return 0;
}