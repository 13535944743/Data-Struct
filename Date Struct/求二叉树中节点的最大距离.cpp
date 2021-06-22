#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string.h>
#include<string>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
//DS������������������������:��ͨ���ݹ��ҵ����������ӽڵ㣬������õݹ�Ļ��˹��ܣ��������͵�ǰ�ڵ�������봫����ǰ�ڵ�
//�������ö����������ʣ�ÿ�θ����������������������ʱ��ȡ�������е�����룬���������е����������ֵ����+1�����¸ýڵ�������ֵ
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
	int left = 0;  //��ÿһ���ڵ�ĵ�����������ұ������������left��right
	int right = 0;
	if (tree == NULL)  return;//������Ҷ�ӽڵ㣬����
	if (tree->lchild) {
		find(tree->lchild, left, right, max_len);//��������Ϊ�գ� �����ݹ�����ߵ������
		left_depth = left > right ? left + 1 : right + 1;//���Լ������µݹ飬���¸ýڵ�������ֵ
	}
	else {
		left_depth = 0;//������Ϊ�գ��ýڵ����������Ϊ0
	}
	if (tree->rchild) {
		find(tree->rchild, left, right, max_len);
		right_depth = left > right ? left + 1 : right + 1;
	}
	else {
		right_depth = 0;
	}
	max_len = max_len > left_depth + right_depth ? max_len : left_depth + right_depth; //ȡ������������ֵ
	MAX[count1] = max_len;
	LEFT[count1] = tree->lchild->data;
	RIGHT[count1] = tree->rchild->data;//ÿ�θ���ʱ����MAX�����max_len����LEFT����ڵ㣬��RIGHT���ҽڵ�
	/*���A: ·������������������ڵ㣬ͨ�����ڵ㣬�ٵ�������������ڵ㡣
	  ���B: ·�����������ڵ㣬��������������������������·����ȡ����ߡ�*/
}
int MAX_Length(BiNode* tree)
{
	if (tree == NULL)  return 0;
	int max_len = 0;  //���������������
	int left_MaxLen = 0;   //�������е������
	int right_MaxDepth = 0;     //�������е������
	find(tree, left_MaxLen, right_MaxDepth, max_len);  //�������
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
