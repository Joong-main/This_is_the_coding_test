#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef pair<int, int> edge;
static vector<vector<edge>> A;
static vector<bool> visited;
static vector<int> m_distance;

void BFS(int node) {
	queue<int> myqueue;
	myqueue.push(node);
	visited[node] = true;

	while (!myqueue.empty()) {
		int now_node = myqueue.front();
		myqueue.pop();
		for (edge i : A[now_node]) { // A[now_node] 에 연결되어 있는 배열에서 값을 하나씩 뽑음 (해당 값은 i에 담김)
			if (!visited[i.first]) {
				visited[i.first] = true;
				myqueue.push(i.first);
				m_distance[i.first] = m_distance[now_node] + i.second; // 거리배열 업데이트
			}
		}
	}
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	A.resize(N + 1);

	for (int i = 0; i < N; i++) {
		int S;
		cin >> S;
		while (true) {
			int E, V;
			cin >> E;
			if (E == -1) {
				break;
			}
			else {
				cin >> V;
			}
			A[S].push_back(edge(E, V));
		}
	}

	m_distance = vector<int>(N + 1, 0);
	visited = vector<bool>(N + 1, false);
	
	BFS(1);
	int MaxNode = 1;
	for (int i = 2; i <= N; i++) {
		if (m_distance[MaxNode] < m_distance[i]) {
			MaxNode = i;
		}
	}

	fill(m_distance.begin(), m_distance.end(), 0); //거리 배열 0으로 초기화
	fill(visited.begin(), visited.end(), 0); //방문 배열 0 초기화
	BFS(MaxNode);
	sort(m_distance.begin(),m_distance.end());
	cout << m_distance[N];
	



	return 0;
}
