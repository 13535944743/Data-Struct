#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string.h>
#include<string>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
struct BiNode {
	char data;
	BiNode* lchild, * rchild;
	int ltag = 1;//0表示线索,1表示子节点
	int rtag = 1;
};
void creatTree(BiNode *&tree) {
	char c;
	cin >> c;
	if (c == '0')  tree = NULL;
	else {
		tree = new BiNode;
		tree->data = c;
		creatTree(tree->lchild);
		creatTree(tree->rchild);
	}
}
void preTravel(BiNode* tree) {
	if (tree != NULL) {
		preTravel(tree->lchild);
		cout << tree->data << " ";
		
		preTravel(tree->rchild);
	}
}
BiNode *pre = NULL;
void inthreadBiTree(BiNode* tree)
{
	if (tree) {
		inthreadBiTree(tree->lchild);

		if (tree->lchild == NULL) {
			tree->ltag = 0;
			tree->lchild = pre;
		}

		if (pre != NULL && pre->rchild == NULL) {
			pre->rtag = 0;
			pre->rchild = tree;
		}

		pre = tree;

		inthreadBiTree(tree->rchild);
	}
}
void InorderThread(BiNode* tree)
{
	BiNode* p = tree;
	while (p != NULL) {
		while (p->ltag == 1) {
			p = p->lchild;
		}
		cout << p->data << " ";
		while (p->rtag == 0 && p->rchild != NULL) {
			p = p->rchild;
			cout << p->data << " ";
		}
		p = p->rchild;
	}
}
int main()
{
	int n;
	cin >> n;
	while (n--) {
		BiNode *tree;
		creatTree(tree);
		preTravel(tree);
		cout << endl;
		inthreadBiTree(tree);
		InorderThread(tree);
		cout << endl;
	}
	return 0;
}