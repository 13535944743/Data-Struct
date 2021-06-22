#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<set>
using namespace std;
set<int> s[60];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int cnt;
		cin >> cnt;
		int x;
		for (int j = 0; j < cnt; j++) {
			cin >> x;
			s[i].insert(x);
		}
		
	}
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int a, b;
		cin >> a >> b;
		int same = 0;
		int size_s1 = s[--a].size();
		int size_s2 = s[--b].size();
		set<int>::iterator  it;
		for (it = s[a].begin(); it != s[a].end(); it++) {
			if (s[b].find(*it) != s[b].end())  same++;
		}
		int beichu = same;
		int chu = size_s1 + size_s2 - same;
		double ans = (beichu * 1.0) / (chu * 1.0) * 100;
		printf("%.2f%%\n", ans);
	}
	return 0;
}