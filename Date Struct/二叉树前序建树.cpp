#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string.h>
#include<string>
#include<cmath>
#include<stack>
using namespace std;
class Node {
public:
	char data;
	Node* lchild;
	Node* rchild;
	Node(char d = '0') {
		data = d;
		lchild = NULL;
		rchild = NULL;
	}
};
class BiTree {
public:
	Node* _root;
	int num = 0;

	BiTree(const char *s) {
		_root = creatBiTree(s);
		num = 0;
	}
	~BiTree() {
		if (_root) {
			destroyBiTree(_root);
		}
	}
	Node* creatBiTree(const char* s) {
		if (s[num] == '\0')   return NULL;
		else if (s[num] == '#') {
			num++;
			return NULL;
		}
		else {
			Node* node = new Node(s[num]);
			num++;
			node->lchild = creatBiTree(s);
			node->rchild = creatBiTree(s);
			return node;
		}
	}
	void destroyBiTree(Node* root) {
		if (!root)  return;
		else {
			destroyBiTree(root->lchild);
			destroyBiTree(root->rchild);
			delete root;
			root = NULL;
		}
	}
	void preorder(Node* node) {
		if (!node)
			return;
		else {
			cout << node->data;
			preorder(node->lchild);
			preorder(node->rchild);
		}
	}
	void inorder(Node* node) {
		if (!node)
			return;
		else {
			inorder(node->lchild);
			cout << node->data;
			inorder(node->rchild);
		}
	}
	void postorder(Node* node) {
		if (!node)
			return;
		else {
			postorder(node->lchild);
			postorder(node->rchild);
			cout << node->data;
		}
	}

	Node* getRoot() {
		return _root;
	}
};
int main()
{
	char a[1010];
	cin >> a;
	BiTree tree(a);
	tree.preorder( tree.getRoot() );
	cout << endl;
	tree.inorder(tree.getRoot());
	cout << endl;
	tree.postorder(tree.getRoot());
	cout << endl;
	return 0;
}
