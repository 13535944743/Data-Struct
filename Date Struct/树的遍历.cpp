#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
struct Node {
	int data;
	struct Node* l, * r;
};
struct Node* creatTree(int* a, int* b, int n) {
	struct Node* fin;
	if (n <= 0) return NULL;
	fin = new Node;
	fin->data = a[n - 1];
	int q;
	for (q = 0; q < n; q++) {
		if (b[q] == a[n - 1]) break;
	}
	fin->l = creatTree(a, b, q);
	fin->r = creatTree(a + q, b + q + 1, n - q - 1);
	return fin;
}
int levelTraverse(Node* tree)
{
	if (tree == NULL) return 0;
	Node* p;
	p = tree;
	queue<Node*> q;
	q.push(p);

	int flag = 0;
	while (!q.empty()) {
		p = q.front();
		if (!flag)   cout << p->data;
		else cout << " " << p->data;
		flag = 1;
		q.pop();
		if (p->l != NULL) q.push(p->l);
		if (p->r != NULL) q.push(p->r);
		
		
	}
}
int main()
{
	int n;
	cin >> n;
	int a[100] = { 0 }, b[100] = { 0 };
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	struct Node *tree;
	tree = new Node;
	tree = creatTree(a, b,  n);
	levelTraverse(tree);
	return 0;
}