#include <iostream>
#include <queue>
using namespace std;
int n;
queue<int> que1;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = NULL;
    }
};
class LinkList
{
public:
    Node *head;
    int len;
    LinkList()
    {
        head = new Node();
        head->next = NULL;
        len = 0;
    }

    void insert(int elem)
    {
        Node *node = new Node();
        node->data = elem;
        Node *p = head;
        if (len == 0)
        {
            head->next = node;
            len++;
            return;
        }
        while (p->next)
        {
            p = p->next;
        }
        node->next = p->next;
        p->next = node;
        len++;
    }
    void Clear()
    {
        head->next = NULL;
    }
};

void display1(LinkList list[])
{
    for (int i = 0; i < 10; i++)
    {
        if (list[i].head->next == NULL)
        {
            cout << i << ":NULL" << endl;
        }
        else
        {
            cout << i << ":->";
            Node *p = list[i].head->next;
            while (p)
            {
                cout << p->data << "->";
                que1.push(p->data);
                p = p->next;
            }
            cout << "^" << endl;
        }
    }
}

void display2(int a[])
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        while (!que1.empty())
        {
            que1.pop();
        }
        LinkList list[10];
        cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            int wei = a[i] % 10;
            list[wei].insert(a[i]);
        }
        display1(list);
        for (int i = 0; i < n; i++)
        {
            a[i] = que1.front();
            que1.pop();
        }
        display2(a);

        int x = 1; //取位数
        while (1)
        {
            for (int i = 0; i < 10; i++)
            {
                list[i].Clear();
            }
            x *= 10;
            int flag = 0;

            for (int i = 0; i < n; i++)
            {
                int temp = a[i] / x;
                if (temp != 0)
                {
                    flag = 1;
                }
                int wei = temp % 10;
                list[wei].insert(a[i]);
            }
            if (!flag)
            {
                break;
            }
            else
            {
                display1(list);
                for (int i = 0; i < n; i++)
                {
                    a[i] = que1.front();
                    que1.pop();
                }
                display2(a);
            }
        }
        cout << endl;
    }
    return 0;
}