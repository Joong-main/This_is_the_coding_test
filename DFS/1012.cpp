#include<iostream>
#include<vector>

using namespace std;

#define MAX 60

static int graph[MAX][MAX];
static int visited[MAX][MAX];

static int dirR[] = {1,-1,0,0};
static int dirC[] = {0,0,1,-1};


void DFS(int y, int x) {

	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int n_y = y+dirR[i];
		int n_x = x+dirC[i];
		
		if(graph[n_y][n_x] ==1 && visited[n_y][n_x] == 0){
			DFS(n_y, n_x);
		}
	}

}


int main(void) {
	
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int M, N, K;
		cin >> M>> N>>K;

		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				graph[i][j] = 0;
				visited[i][j] = 0;
			}
	
		}

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x>> y;
			graph[y + 1][x + 1] = 1;
		}

		int ans = 0;
		for (int i = 0; i < N + 1; i++) {
			for (int j = 0; j < M + 1; j++) {
				if (graph[i][j] == 1 && visited[i][j] == 0) {
					DFS(i, j);
					ans++;
				}
			}
		}

		cout << ans<<"\n";

	}
	
	return 0;
}
