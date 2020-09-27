
#include <stdio.h>
#include <stdlib.h>
/**
 * 单链表操作
 */
typedef struct node //单列表结点类型
{
    int data;          //数据域
    struct node *next; //指针域
} ListNode;

/**
 * 头插法创建线性表，并返回头指针
 */
ListNode *creatLinkListHead(void)
{
    ListNode *head, *p;
    int data;
    //创建表头结点
    head = (ListNode *)malloc(sizeof(ListNode));
    head->next = NULL;
    //循环创建线性表
    while (1)
    {
        scanf("%d", &data);
        if (data == -1)
            break;
        p = (ListNode *)malloc(sizeof(ListNode));
        p->data = data;
        p->next = head->next;
        head->next = p;
    }
    return head;
}
/**
 * 尾插法创建线性表，并返回头指针
 */
ListNode *creatLinkListEnd(void)
{
    ListNode *head, *p, *q;
    int data;
    //创建表结点
    head = (ListNode *)malloc(sizeof(ListNode));
    head->next = NULL;
    q = head;
    //循环创建列表
    while (1)
    {
        scanf("%d", &data);
        if (data == -1)
            break;
        p = (ListNode *)malloc(sizeof(ListNode));
        p->data = data;
        p->next = q->next;
        q->next = p;
        q = p;
    }
    return head;
}
/**
 * 打印单链表
 */
void printListNode(ListNode *head) /*显示线性表的值*/
{
    ListNode *p = head->next;
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 * 按序号查找第i个结点，并返回指向该节点的值
 */
int getNodeByIndex(ListNode *head, int index)
{
    ListNode *p = head->next;
    int j = 1;
    while (p != NULL && j < index)
    {
        p = p->next;
        j++;
    }
    if (index == j)
        return p->data;
    else
        return -94598;
}
/**
 * 按值查找结点，并返回指向该结点的指针
 */
ListNode *getNodeByValue(ListNode *head, int value)
{
    ListNode *p = head->next;
    int j = 1;
    while (p != NULL && p->data != value)
        p = p->next;
    if (p->data == value)
        return p;
    else
    {
        printf("we can't find it");
        return NULL;
    }
}
/**
 * 在线性表中插入一个整数value
 */
void insertNode(ListNode *head, int index, int value)
{
    ListNode *p = head, *q;
    int j = 1;
    while (p != NULL && j < index)
    {
        p = p->next;
        j++;
    }
    if (j != index)
        printf("the i is too big or too small");
    else
    {
        q = (ListNode *)malloc(sizeof(ListNode));
        q->data = value;
        q->next = p->next;
        p->next = q;
    }
}
/**
 * 按序号删除第i个结点
 */
void deleteNodeByIndex(ListNode *head, int index)
{
    ListNode *p = head, *q = head->next;
    int j = 1;
    while (q != NULL && j < index)
    {
        p = q;
        q = q->next;
        j++;
    }
    if (j == index)
    {
        p->next = q->next;
        free(q);
        q = p->next;
    }
    else
        printf("index input error");
}
/**
 * 按值删除表中的所有value值
 */
void deleteNodeByValue(ListNode *head, int value)
{
    ListNode *p = head, *q = head->next;
    while (q != NULL)
    {
        if (q->data == value)
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
        p = q;
        q = q->next;
    }
}
/**
 * 按值删除表中的第一个X
 */
void deleteNodeFirstValue(ListNode *head, int value)
{
    ListNode *p = head, *q = head->next;
    while (q != NULL && q->data != value)
    {
        p = q;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    else
    {
        printf("error");
    }
}
/**
 * 删除重复的值
 */
void deleteNodeRepeatValue(ListNode *head)
{
    ListNode *p = head->next, *q, *r;
    while (p != NULL)
    {
        q = p;
        r = q->next;
        while (r != NULL)
        {
            if (r->data == p->data)
            {
                q->next = r->next;
                free(r);
                r = q->next;
            }
            else
            {
                q = r;
                r = r->next;
            }
        }
        p = p->next;
    }
}

/**
 * 将两个递增序列La,Lb合并到La
 */
void mergeOrderedLinkList(ListNode *La, ListNode *Lb)
{
    ListNode *p = La->next, *q = Lb->next, *r = La, *ptr;
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            r->next = p;
            r = p;
            p = p->next;
        }
        else if (p->data > q->data)
        {
            r->next = q;
            r = q;
            q = q->next;
        }
        else
        {
            r->next = p;
            r = p;
            p = p->next;
            ptr = q;
            q = q->next;
            free(ptr);
        }
    }
    if (p == NULL)
        r->next = q;
    else
        r->next = p;
    free(Lb);
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *p1 = l1;
    ListNode *p2 = l2;
    ListNode *ans = (ListNode *)malloc(sizeof(ListNode));
    ans->data = 0;
    ListNode *p = 0;
    int c = 0;
    while (p1 != 0 || p2 != 0 || c != 0)
    {
        if (p == 0)
        {
            p = ans;
        }
        else
        {
            p->next = (ListNode *)malloc(sizeof(ListNode));
            p->next->data = 0;
            p = p->next;
        }
        int a = p1 != 0 ? p1->data : 0;
        int b = p2 != 0 ? p2->data : 0;
        int s = (a + b + c) % 10;
        c = (a + b + c) / 10;
        p->data = s;
        p->next = 0;
        p1 = p1 == 0 ? 0 : p1->next;
        p2 = p2 == 0 ? 0 : p2->next;
    }
    return ans;
}
int main()
{
    ListNode *la;
    printf("Input data(end as -1): \n");
    la = creatLinkList_end();
    printListNode(la);
    ListNode *lb;
    printf("Input data(end as -1): \n");
    lb = creatLinkList_end();
    printListNode(lb);
    printListNode(addTwoNumbers(la, lb));
}
