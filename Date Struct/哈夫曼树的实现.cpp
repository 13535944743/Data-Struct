#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string.h>
#include<string>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
struct HTNode {
	int weight;
	int lchild, rchild, parent;
};
class HTree {
private:
	HTNode* node;
	int num, m;
	stack<int> code;
	int setcode(int weight);
public:
	HTree(int n, int w[]) {
		num = n;
		m = 2 * n - 1;
		node = new HTNode[m];
		for (int i = 0; i < n; i++) {
			node[i].weight = w[i];
		}
		for (int i = 0; i < m; i++) {
			node[i].lchild = 0;
			node[i].rchild = 0;
			node[i].parent = 0;
		}
		creatHT();
	}
	void select(int& s1, int& s2) {
		for (int i = 0; i < num; i++) {
			if (node[i].parent == 0) {
				s1 = i;
				break;
			}
		}
		for (int i = 0; i < num; i++) {
			if ((node[s1].weight > node[i].weight) && (node[i].parent == 0)) {
				s1 = i;
			}
		}

		for (int i = 0; i < num; i++) {
			if (node[i].parent == 0 && i != s1) {
				s2 = i;
				break;
			}
		}
		for (int i = 0; i < num; i++) {
			if ((node[s2].weight > node[i].weight) && (node[i].parent == 0) && i != s1) {
				s2 = i;
			}
		}
	}
	void creatHT() {
		for (int i = num; i < m; i++) {
			int s1, s2;
			select(s1, s2);
			node[s1].parent = i;
			node[s2].parent = i;
			node[i].lchild = s1;
			node[i].rchild = s2;
			node[i].weight = node[s1].weight + node[s2].weight;
		}
	}
	void print() {

	}
	int search(int weight) {

	}
	void printHTcode() {

	}
};
int main()
{
	return 0;
}