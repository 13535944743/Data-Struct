#include <iostream>
using namespace std;

#define LH 1  // 左高
#define EH 0  // 等高
#define RH -1 // 右高

class BiNode
{
public:
    int key; // 关键值
    int bf;  // 平衡因子
    BiNode *lChild, *rChild;
    BiNode(int kValue, int bValue)
    {

        key = kValue;
        bf = bValue;
        lChild = NULL;
        rChild = NULL;
    }

    ~BiNode()
    {
        key = 0;
        bf = 0;
        lChild = NULL;
        rChild = NULL;
    }
};

// 二叉排序树
class BST
{
private:
    BiNode *root; // 根结点指针
    void rRotate(BiNode *&p);
    void lRotate(BiNode *&p);
    void leftBalance(BiNode *&t);
    void deleteleftBalance(BiNode *&t);
    void rightBalance(BiNode *&t);
    void deleterightBalance(BiNode *&t);
    int insertAVL(BiNode *&t, int key, bool &taller); // 插入元素并做平衡处理
    int deleteAVL(BiNode *&t, int key, bool &shorter);
    void deleteDouble(BiNode *&t, bool &shorter);
    void inOrder(BiNode *p);

public:
    BST();
    BiNode *getRoot();
    void insertAVL(int key); // 二叉排序树插入元素
    void deleteAVL(int key);
    ~BST();
    void inOrder(); // 中序遍历
};

// 以p为根的二叉排序树作右旋处理
void BST::rRotate(BiNode *&p)
{
    if (p == NULL || p->lChild == NULL)
        return;
    BiNode *lc = p->lChild;
    p->lChild = lc->rChild;
    lc->rChild = p;
    p = lc;
}

// 以p为根的二叉排序树作左旋处理
void BST::lRotate(BiNode *&p)
{
    if (p == NULL || p->rChild == NULL)
        return;
    BiNode *rc = p->rChild;
    p->rChild = rc->lChild;
    rc->lChild = p;
    p = rc;
}

// t为根的二叉排序树作左平衡旋转处理
void BST::leftBalance(BiNode *&t)
{
    BiNode *lc = t->lChild;
    BiNode *rd;
    switch (lc->bf)
    {
    case LH:
        t->bf = lc->bf = EH;
        rRotate(t);
        break;
    case EH:
        lc->bf = RH;
        rRotate(t);
        break;
    case RH:
        rd = lc->rChild;
        switch (rd->bf)
        {
        case LH:
            t->bf = RH;
            lc->bf = EH;
            break;
        case EH:
            t->bf = lc->bf = EH;
            break;
        case RH:
            t->bf = EH;
            lc->bf = LH;
            break;
        }
        rd->bf = EH;
        lRotate(t->lChild);
        rRotate(t);
    }
}
void BST::deleteleftBalance(BiNode *&t)
{
    BiNode *lc = t->lChild;
    BiNode *rd;
    switch (lc->bf)
    {
    case LH:
        rRotate(t);
        break;
    case EH:
        rRotate(t);
        break;
    case RH:
        lRotate(t->rChild);
        rRotate(t);
        break;
    }
}
// t为根的二叉排序树作右平衡旋转处理
void BST::rightBalance(BiNode *&t)
{
    BiNode *lc = t->rChild;
    BiNode *rd;
    switch (lc->bf)
    {
    case RH:
        t->bf = lc->bf = EH;
        lRotate(t);
        break;
    case EH:
        rd->bf = LH;
        lRotate(t);
        break;
    case LH:
        rd = lc->lChild;
        switch (rd->bf)
        {
        case RH:
            t->bf = LH;
            lc->bf = EH;
            break;
        case EH:
            t->bf = lc->bf = EH;
            break;
        case LH:
            t->bf = EH;
            lc->bf = RH;
            break;
        }
        rd->bf = EH;
        rRotate(t->rChild);

        lRotate(t);
    }
}
void BST::deleterightBalance(BiNode *&t)
{
    BiNode *lc = t->rChild;
    BiNode *rd;
    switch (lc->bf)
    {
    case LH:
        rRotate(t->rChild);
        lRotate(t);
        break;
    case EH:
        lRotate(t);
        break;
    case RH:
        lRotate(t);
        break;
    }
}
int BST::insertAVL(BiNode *&t, int key, bool &taller)
{
    if (!t)
    {
        t = new BiNode(key, EH);
        taller = true;
    }
    else
    {
        if (key == t->key)
        {
            taller = false;
            return 0;
        }
        if (key < t->key)
        {
            if (!insertAVL(t->lChild, key, taller))
                return 0;
            if (taller)
            {
                switch (t->bf)
                {
                case LH:
                    leftBalance(t);
                    taller = false;
                    break;
                case EH:
                    t->bf = LH;
                    taller = true;
                    break;
                case RH:
                    t->bf = EH;
                    taller = false;
                    break;
                }
            }
        }
        else
        {
            if (!(insertAVL(t->rChild, key, taller)))
                return 0;
            if (taller)
            {
                switch (t->bf)
                {
                case LH:
                    t->bf = EH;
                    taller = false;
                    break;
                case EH:
                    t->bf = RH;
                    taller = true;
                    break;
                case RH:
                    rightBalance(t);
                    taller = false;
                    break;
                }
            }
        }
    }
    return 1;
}
int BST::deleteAVL(BiNode *&t, int key, bool &shorter)
{
    if (t == NULL)
    {
        return 0;
    }
    else if (t->key == key)
    {
        if (t->lChild == NULL && t->rChild == NULL)
        {
            t = NULL;
            shorter = true;
        }
        else if (t->lChild == NULL)
        {
            BiNode *temp = t;
            t = t->rChild;
            delete temp;
            shorter = true;
        }
        else if (t->rChild == NULL)
        {
            BiNode *temp = t;
            t = t->lChild;
            delete temp;
            shorter = true;
        }
        else
        {
            deleteDouble(t, shorter);
        }
    }
    else if (key < t->key) //左子树中继续查找
    {
        if (!deleteAVL(t->lChild, key, shorter)) //未删除
        {
            return 0;
        }
        if (shorter)
        {
            switch (t->bf)
            {
            case LH:
                t->bf = EH;
                shorter = true;
                break;
            case EH:
                t->bf = RH;
                shorter = false;
                break;
            case RH:
                if (t->rChild->bf == EH)
                {
                    shorter = false;
                }
                else
                {
                    shorter = true;
                }
                if (shorter)
                {
                    rightBalance(t);
                }
                /*else
                {
                    deleterightBalance(t);
                }*/
                break;
            }
        }
    }
    else //右子树中继续查找
    {
        if (!deleteAVL(t->rChild, key, shorter)) //未删除
        {
            return 0;
        }
        if (shorter)
        {
            switch (t->bf)
            {
            case LH:
                if (t->lChild->bf == EH)
                {
                    shorter = false;
                }
                else
                {
                    shorter = true;
                }
                if (shorter)
                {
                    leftBalance(t);
                }
                /*else
                {
                    deleteleftBalance(t);
                }*/
                break;
            case EH:
                t->bf = LH;
                shorter = false;
                break;
            case RH:
                t->bf = EH;
                shorter = true;
                break;
            }
        }
    }
    return 1;
}
void BST::deleteDouble(BiNode *&t, bool &shorter)
{
    {
        BiNode *q = t;
        BiNode *s = t->lChild;
        BiNode *temp = q;
        while (s->rChild)
        {
            q = s;
            s = s->rChild;
        }
        t->key = s->key;
        if (q != t)
        {
            q->rChild = s->lChild;
            if (q->bf == LH)
            {
                shorter = true;
            }
            else if (q->bf == EH)
            {
                q->bf = RH;
                shorter = false;
            }
            else
            {
                q->bf = EH;
                if (temp->bf == RH)
                {
                    shorter = true;
                }
                else
                    shorter = false;
            }
        }
        else
        {
            if (q->bf == LH)
            {
                shorter = true;
            }
            else if (q->bf == EH)
            {
                q->bf = RH;
                shorter = false;
            }
            else
            {
                q->bf = EH;
                shorter = true;
            }
            q->lChild = s->lChild;
        }
        if (shorter)
        {
            deleterightBalance(t);
        }
    }
}
BiNode *BST::getRoot()
{
    return root;
}
void BST::inOrder(BiNode *p)
{
    if (p)
    {
        inOrder(p->lChild);
        cout << p->key << ':' << p->bf << ' ';
        inOrder(p->rChild);
    }
    return;
}

// 二叉排序树初始化
BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    root = NULL;
}

// 插入元素并作平衡处理
void BST::insertAVL(int key)
{
    bool taller = false;
    insertAVL(root, key, taller);
}
void BST::deleteAVL(int key)
{
    bool shorter = false;
    deleteAVL(root, key, shorter);
}

// 中序遍历
void BST::inOrder()
{
    inOrder(root);
}
int setBf(BiNode *&t)
{
    if (t == NULL)
    {
        return 0;
    }
    int l = setBf(t->lChild);
    int r = setBf(t->rChild);
    if (t != NULL)
    {
        t->bf = l - r;
    }
    if (l > r)
    {
        return l + 1;
    }
    else
    {
        return r + 1;
    }
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        // 构建二叉平衡树，并在插入元素时做平衡处理
        int n, elem;
        cin >> n;
        BST tree;
        while (n--)
        {
            cin >> elem;
            tree.insertAVL(elem);
        }
        tree.inOrder();
        cout << endl;
        int m;
        cin >> m;
        while (m--)
        {
            cin >> elem;
            tree.deleteAVL(elem);
            BiNode *t = tree.getRoot();
            setBf(t);
            tree.inOrder();
            cout << endl;
            cout << " ";
        }
    }

    return 0;
}