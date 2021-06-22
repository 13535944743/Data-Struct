#include<iostream>
#include<string>
#include<stack>
using namespace std;
int MAX = 9999;
stack<char> st;
char** fin;
class HTNode {
public:
    int weight;
    int parent, lchild, rchild;
};
class HuffmanTree {
    int num, m;
    HTNode* ht;
    HuffmanTree(int n, int w[]) {
        num = n;
        m = 2 * n - 1;
        ht = new HTNode[m + 1];
        for (int i = 1; i <= n; i++)
            ht[i].weight = w[i];
        for (int i = 1; i <= m; i++) {
            ht[i].parent = 0;
            ht[i].lchild = 0;
            ht[i].rchild = 0;
        }
        buildHuffmanTree();
    }
    void buildHuffmanTree() {
        int s1 = 0, s2 = 0;
        for (int i = num + 1; i <= m; i++) {
            Select(i - 1, s1, s2);
            ht[s1].parent = i;
            ht[s2].parent = i;

            ht[i].lchild = s1;
            ht[i].rchild = s2;
            ht[i].weight = ht[s1].weight + ht[s2].weight;
        }
    }
    void Select(int pos, int& s1, int& s2) {
        int w1 = MAX, w2 = MAX;
        for (int i = 1; i <= pos; i++) {
            if (w1 > ht[i].weight && ht[i].parent == 0) {
                w1 = ht[i].weight;
                s1 = i;
            }
        }
        for (int i = 1; i <= pos; i++) {
            if (w1 > ht[i].weight && ht[i].parent == 0 && i != s1) {
                w2 = ht[i].weight;
                s2 = i;
            }
        }
    }
    void coding() {
        
        char* cd = new char[num];
        cd[num - 1] = '\0';
        for (int i = 1; i <= num; i++) {
           int start = num - 1;
           for (int c = i, f = ht[i].parent; f != 0; c = f, f = ht[f].parent) {
               if (ht[f].lchild == c)  cd[--start] = '0';
               else cd[--start] = '1';
           }
           cout << cd << endl;
        }
    }
};
int main()
{
    
    return 0;
}