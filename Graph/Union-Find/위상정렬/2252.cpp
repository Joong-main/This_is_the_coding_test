#include<iostream>
#include<vector>
#include<queue>

using namespace std;

static vector<int> a[32000 + 1];
static vector<int> indegree(32000 + 1,0);
static queue<int> q;

int main(void) {

	int n, m;
	cin >> n >> m;
	

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		a[s].push_back(e);
		indegree[e]++;
	}
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now<<" ";
		for (int i = 0; i < a[now].size(); i++) {
			int value = a[now][i];
			indegree[value]--;
			if (indegree[value] == 0) {
				q.push(value);
			}
		}
	
	}


	return 0;
}
