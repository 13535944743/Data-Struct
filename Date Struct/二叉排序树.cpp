#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<iomanip>
using namespace std;
typedef struct BiNode
{
    int data;
    BiNode* lchild, * rchild;
};
bool SearchBST(BiNode* tree, int key, BiNode* f, BiNode*& p) //tree当前，f上一个
{
    if (!tree)
    {
        p = f;
        return 0;
    }
    else if (key == tree->data)
    {
        p = tree;
        return true;
    }
    else if (key < tree->data)
    {
        return SearchBST(tree->lchild, key, tree, p);
    }
    else  return SearchBST(tree->rchild, key, tree, p);
}
void InsertBST(BiNode*& tree, int e)
{
    BiNode* p = NULL;
    if (!SearchBST(tree, e, NULL, p))
    {
        BiNode* s = new BiNode();
        s->data = e;
        s->lchild = NULL;
        s->rchild = NULL;
        if (!p)
        {
            tree = s;
        }
        else if (e < p->data)
        {
            p->lchild = s;
        }
        else p->rchild = s;
        return;
    }
    return;
}
void Delete(BiNode*& tree)
{
    if (tree->lchild == NULL && tree->rchild == NULL)
    {
        tree = NULL;
    }
    else if (tree->rchild == NULL)
    {
        BiNode* temp = tree;
        tree = tree->lchild;
        delete temp;
    }
    else if (tree->lchild == NULL)
    {
        BiNode* temp = tree;
        tree = tree->rchild;
        delete temp;
    }
    else
    {
        BiNode* temp = tree;
        BiNode* s = tree->lchild;
        while (s->rchild != NULL)
        {
            temp = s;
            s = s->rchild;
        }
        tree->data = s->data;
        if (temp != tree)
        {
            temp->rchild = s->lchild;
        }
        else
        {
            temp->lchild = s->lchild;
        }
        delete s;
    }
}
void DeleteBST(BiNode*& tree, int key)
{
    if (tree == NULL)
    {
        return;
    }
    if (key == tree->data)
    {
        Delete(tree);
        return;
    }
    else if (key < tree->data)
    {
        DeleteBST(tree->lchild, key);
    }
    else
    {
        DeleteBST(tree->rchild, key);
    }
}
void preTravel(BiNode* tree)
{
    if (tree != NULL) {
        preTravel(tree->lchild);
        cout << tree->data << " ";
        preTravel(tree->rchild);
    }
}
int main()
{
    BiNode* tree = NULL;
    for (int i = 0; i < 9; i++)
    {
        int m;
        cin >> m;
        InsertBST(tree, m);
    }
    preTravel(tree);
    cout << endl;
    DeleteBST(tree, 6);
    preTravel(tree);
    return 0;
}