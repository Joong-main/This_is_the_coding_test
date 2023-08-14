#include<iostream>
#include<vector>

using namespace std;

static int graph[100][100] = {0};
static int visited[100] = {0};
static int node_cnt;

void DFS(int idx) {
	visited[idx] = 1;
	for (int i = 1; i <= node_cnt; i++) {
		if (visited[i] == 0 && graph[idx][i] == 1) {
			DFS(i);
		}
	}
}


int main(void) {

	int edge_cnt;
	int v1, v2;
	int cnt=0;

	cin >> node_cnt;
	cin >> edge_cnt;

	for (int i = 0; i < edge_cnt; i++) {
		cin >> v1 >> v2;
		graph[v1][v2] = 1;
		graph[v2][v1] = 1;

	}
	DFS(1);

	for (int i = 1; i <= node_cnt; i++) {
		if (visited[i] == 1) {
			cnt++;
		}
	}

	cout << cnt-1;


	return 0;
}
