#include <iostream>
using namespace std;

#define ok 0
#define error -1

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode()
    {
        next = NULL;
    }
};
class LinkList
{
public:
    ListNode *head;
    int len;
    LinkList()
    {
        head = new ListNode();
        len = 0;
    }
    ~LinkList()
    {
        ListNode *p, *q;
        p = head;
        while (p != NULL)
        {
            q = p;
            p = p->next;
            delete q;
        }
        len = 0;
        head = NULL;
    }
    ListNode *LL_index(int i)
    {
        int index = 0;
        ListNode *p = head;
        while (p)
        {
            if (index == i)
            {
                return p;
            }
            p = p->next;
            index++;
        }
        return NULL;
    }
    int LL_insert(int i, int item)
    {
        ListNode *index = LL_index(i - 1);
        if (index == NULL)
        {
            cout << "error" << endl;
            return error;
        }
        else
        {
            ListNode *p = new ListNode();
            p->data = item;
            p->next = index->next;
            index->next = p;
            len++;
            return ok;
        }
    }
    int change(int x1, int x2)
    {
        if (x1 <= 0 || x1 > len || x2 <= 0 || x2 > len)
        {
            return error;
        }
        ListNode *index1 = LL_index(x1 - 1);
        ListNode *index2 = LL_index(x2 - 1);

        ListNode *p = index1->next;
        ListNode *q = index2->next;

        ListNode *temp = q->next;
        index1->next = q;
        q->next = p->next;

        index2->next = p;
        p->next = temp;
        return ok;
    }
    void LL_display()
    {
        ListNode *p = head->next;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};
int main()
{
    LinkList ll;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        ll.LL_insert(i, m);
    }
    ll.LL_display();
    int weizhi1, weizhi2;
    cin >> weizhi1 >> weizhi2;
    if (ll.change(weizhi1, weizhi2) == ok)
    {
        ll.LL_display();
    }
    else
    {
        cout << "error" << endl;
    }
    cin >> weizhi1 >> weizhi2;
    if (ll.change(weizhi1, weizhi2) == ok)
    {
        ll.LL_display();
    }
    else
    {
        cout << "error" << endl;
    }
    return 0;
}