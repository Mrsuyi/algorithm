#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Trie
{
	int cnt = 0;
	int children[26] = {0};
} tries[1000000];
int len = 1;

void insert(const char* c)
{
	int i = 0;
	while (*c != '\0')
	{
		if (tries[i].children[*c - 'a'] == 0)
			tries[i].children[*c - 'a'] = len++;
		
	}
}

int get()
{
	
}

int main()
{
	int N, M;
	cin >> N;
	Trie* root = new Trie();
	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;
		root->insert(&s[0]);
	}
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		string s;
		cin >> s;
		cout << root->get(&s[0]) << endl;
	}
	return 0;
};