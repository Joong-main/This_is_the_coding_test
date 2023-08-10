#include<iostream>
#include<vector>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
static bool arrive;

void DFS(int now, int depth) {

	if (depth == 5 || arrive == true) {
		arrive = true;
		return;
	}
	
	visited[now] = true;
	
	for (int i : A[now]) {
		if (!visited[i]) {
			DFS(i, depth + 1);
		}
	}
	
	visited[now] = false;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	arrive = false;
	A.resize(N);
	visited = vector<bool>(N, false);
	
	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		A[start].push_back(end);
		A[end].push_back(start);
	}

	for (int i = 0; i < N; i++) {
		
		DFS(i, 1);

		if (arrive) {
			break;
		}
	}

	if (arrive) {
		cout << 1 << "\n";
	}

	else {
		cout << 0 << "\n";
	}


	return 0;
}
