#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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