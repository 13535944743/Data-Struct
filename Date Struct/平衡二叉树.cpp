#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<iomanip>
#include "test.h"
#define LH 1
#define EH 0
#define RH -1
using namespace std;
typedef struct BSTNode
{
    int data;
    int bf;
    BSTNode* lchild, * rchild;
};
void R_Rotate(BSTNode*& tree)
{
    BSTNode* lc = tree->lchild;
    tree->lchild = lc->rchild;
    lc->rchild = tree;
    tree = lc;
}
void L_Rotate(BSTNode*& p)
{
    BSTNode* rc = p->rchild;
    p->rchild = rc->lchild;
    rc->lchild = p;
    p = rc;
}
void LeftBalance(BSTNode*& tree)
{
    BSTNode* lc = tree->lchild;
    BSTNode* rd;
    switch (lc->bf) 
    {
        case LH:
            tree->bf = lc->bf = EH;
            R_Rotate(tree);
            break;
        case RH:
            rd = lc->rchild;
        switch (rd->bf)
        {
            case LH:
                tree->bf = RH;
                lc->bf = EH;
                break;
            case EH:
                tree->bf = lc->bf = EH;
                break;
            case RH:
                tree->bf = EH;
                lc->bf = LH;
                break;
        }
        rd->bf = EH;
        L_Rotate(tree->lchild);
        R_Rotate(tree);
    }
}
void RightBalance(BSTNode*& tree)
{
    BSTNode* lc = tree->rchild;
    BSTNode* rd;
    switch (lc->bf)
    {
    case RH:
        tree->bf = lc->bf = EH;
        L_Rotate(tree);
        break;
    case LH:
        rd = lc->lchild;
        switch (rd->bf)
        {
            case LH:
                tree->bf = RH;
                lc->bf = EH;
                break;
            case EH:
                tree->bf = lc->bf = EH;
                break;
            case RH:
                tree->bf = EH;
                lc->bf = LH;
                break;
        }
        rd->bf = EH;
        R_Rotate(tree->lchild);
        L_Rotate(tree);
    }
}
int InsertAVL(BSTNode*& tree, int e, bool& taller)
{
    if (!tree)
    {
        tree = new BSTNode();
        tree->data = e;
        tree->lchild = tree->rchild = NULL;
        tree->bf = EH;
        taller = true;
    }
    else
    {
        if (e == tree->data)
        {
            taller = false;
            return 0;
        }
        if (e < tree->data)
        {
            if (!InsertAVL(tree->lchild, e, taller))    return 0;
            if (taller)
            {
                switch (tree->bf)
                {
                case LH:
                    LeftBalance(tree);
                    taller = false;
                    break;
                case EH:
                    tree->bf = LH;
                    taller = false;
                    break;
                case RH:
                    tree->bf = EH;
                    taller = false;
                    break;
                }
            }
        }
        else
        {
            if (!(InsertAVL(tree->rchild, e, taller)))  return 0;
            if (taller)
            {
                switch (tree->bf)
                {
                case LH:
                    tree->bf = EH;
                    taller = false;
                    break;
                case EH:
                    tree->bf = RH;
                    taller = true;
                    break;
                case RH:
                    RightBalance(tree);
                    taller = false;
                    break;
                }
            }

        }
    }
            return 1;
}
void InorderTra(BSTNode* tree)
{
    if (tree->lchild != NULL)
    {
        InorderTra(tree->lchild);
    }
    cout << tree->data << " ";
    if (tree->rchild != NULL)
    {
        InorderTra(tree->rchild);
    }
}
int main()
{
    int a[] = { 1,23,45,34,98,9,4,35,23 };
    BSTNode* tree = NULL, pos;
    bool taller;
    for (int i = 0; i < 9; i++)
    {
        InsertAVL(tree, a[i], taller);
    }
    InorderTra(tree);
    return 0;
}