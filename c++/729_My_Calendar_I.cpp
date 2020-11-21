#include <iostream>
#include <vector>

using namespace std;
class MyCalendar
{
public:
    struct node
    {
        int start;
        int end;
        struct node *left;
        struct node *right;
    };
    node *getnewnode(int s, int e)
    {
        struct node *temp = new node;
        temp->start = s;
        temp->end = e;
        temp->right = NULL;
        temp->left = NULL;
        return temp;
    }
    struct node *root;

    MyCalendar()
    {
        root = NULL;
    }
    bool book(int s, int e)
    {
        e--;
        if (root == NULL)
        {
            root = getnewnode(s, e);
            return 1;
        }
        struct node *temp = root;
        while (temp)
        {

            if ((temp->start <= s && temp->end >= s) || (temp->start <= e && temp->end >= e))
            {
                return 0;
            }
            if ((temp->start >= s && temp->start <= e) || (temp->end >= s && temp->end <= e))
            {
                return 0;
            }

            if (s <= temp->start)
            {
                if (temp->left == NULL)
                {
                    temp->left = getnewnode(s, e);
                    break;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = getnewnode(s, e);
                    break;
                }
                temp = temp->right;
            }
        }
        return 1;
    }
};
int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}
