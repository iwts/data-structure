// 动态字典树，样例是POJ2503题

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define MAXLIST 110000

using namespace std;

int trie[MAXLIST][10];
int tree_point;

void init_tree() {
	tree_point = 1;
	memset(trie, 0, sizeof(trie));
}

void insert_tree(string s) {
	int next_p = 0, temp;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		temp = s[i] - '0';
		if (!trie[next_p][temp]) {
			trie[next_p][temp] = tree_point++;
		}
		next_p = trie[next_p][temp];
	}
}

int Find(string s) {
	int now_p = 0, temp;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		int temp = s[i] - '0';
		if (!trie[now_p][temp]) {
			return 0;
		}
		now_p = trie[now_p][temp];
	}
	for (int j = 0; j < 10; j++) {
		if (trie[now_p][j]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int M;
	cin >> M;
	while (M--) {
		init_tree();
		int N;
		cin >> N;
		getchar();
		string s;
		vector<string> v;
		while (N--) {
			cin >> s;
			v.push_back(s);
			insert_tree(s);
		}
		int flag = 0;
		for (int i = 0; i < v.size(); i++) {
			if (!Find(v[i])) {
				cout << "NO" << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << "YES" << endl;
		}
	}

	system("pause");
	return 0;
}
