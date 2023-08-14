#include<iostream>
#include<vector>

#define MAX 1000

using namespace std;

static vector<int> arr[MAX];
static vector<int> visited(MAX,0);

void DFS(int node) {
	if (visited[node] == 1) {
		return;
	}

	visited[node] = 1;

	for (int i = 0; i < (int)arr[node].size(); i++) {
		if (visited[arr[node][i]] == 0) {
			DFS(arr[node][i]);
		}
	}
}


int main(void) {

	int n, m;
	int v1, v2;
	int cnt = 0;
	
	cin >> n >> m;

	// 인접리스트 생성
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2;
		arr[v1].push_back(v2);
		arr[v2].push_back(v1);
	}


	/* 인접 리스트 테스트 출력
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < arr[i].size();j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	*/

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			cnt++;
			DFS(i);
		}
	}

	cout << cnt;

	return 0;
}
