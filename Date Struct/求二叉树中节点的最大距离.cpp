#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string.h>
#include<string>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
//DS二叉树—二叉树结点的最大距离:先通过递归找到左边最深的子节点，最后利用递归的回退功能，把最深点和当前节点间的最长距离传给当前节点
//并且利用二叉树的性质，每次更新左子树和右子树最长距离时，取左子树中的最长距离，和右子树中的最长距离的最大值，并+1，更新该节点的最长距离值
int MAX[1010];
char LEFT[1010], RIGHT[1010];
int count1 = 0;
typedef struct BiNode {
	char data;
	BiNode* lchild, * rchild;
};
void buildTree(BiNode*& tree)
{
	char c;
	cin >> c;
	if (c == '#')  tree = NULL;
	else {
		tree = new BiNode;
		tree->data = c;
		buildTree(tree->lchild);
		buildTree(tree->rchild);
	}
}
void find(BiNode* tree, int& left_depth, int& right_depth, int& max_len)
{
	int left = 0;  //找每一个节点的的左边最长距离和右边最长距离先重置left和right
	int right = 0;
	if (tree == NULL)  return;//遍历到叶子节点，回退
	if (tree->lchild) {
		find(tree->lchild, left, right, max_len);//左子树不为空， 继续递归求左边的最长距离
		left_depth = left > right ? left + 1 : right + 1;//可以继续向下递归，更新该节点的最长距离值
	}
	else {
		left_depth = 0;//左子树为空，该节点的左边最长距离为0
	}
	if (tree->rchild) {
		find(tree->rchild, left, right, max_len);
		right_depth = left > right ? left + 1 : right + 1;
	}
	else {
		right_depth = 0;
	}
	max_len = max_len > left_depth + right_depth ? max_len : left_depth + right_depth; //取两种情况的最大值
	MAX[count1] = max_len;
	LEFT[count1] = tree->lchild->data;
	RIGHT[count1] = tree->rchild->data;//每次更新时，用MAX数组存max_len，用LEFT存左节点，用RIGHT存右节点
	/*情况A: 路径经过左子树的最深节点，通过根节点，再到右子树的最深节点。
	  情况B: 路径不穿过根节点，而是左子树或右子树的最大距离路径，取其大者。*/
}
int MAX_Length(BiNode* tree)
{
	if (tree == NULL)  return 0;
	int max_len = 0;  //保存两点间的最长距离
	int left_MaxLen = 0;   //左子树中的最长距离
	int right_MaxDepth = 0;     //右子树中的最长距离
	find(tree, left_MaxLen, right_MaxDepth, max_len);  //找最长距离
	return max_len;
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		BiNode* tree;
		buildTree(tree);
		int m = MAX[0];
		int index = 0;
		for (int i = 0; i < count1; i++) {
			if (MAX[i] > m) index = i;
		}
		cout << MAX[index] << ":";
		if (MAX[index] != 0) cout << LEFT[index] << " " << RIGHT[index];
		else cout << endl;
	}
	return 0;
}
