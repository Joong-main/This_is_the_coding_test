#include<iostream>
#include<vector>
using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int size, query,num;
	int r1, c1, r2, c2;
	cin >> size >> query;

	vector<vector<int>> map(size + 1, vector<int>(size + 1, 0));
	vector<vector<int>> sum_map(size+1,vector<int>(size+1,0));


	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			cin >> num;
			map[i][j] = num;
		}
	}

	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			sum_map[i][j] = sum_map[i - 1][j] + sum_map[i][j - 1] - sum_map[i - 1][j - 1] + map[i][j];
		}
	}

	for (int i = 0; i < query; i++) {
		cin >> r1 >> c1 >> r2 >> c2;
		int ans = sum_map[r2][c2] - sum_map[r1 - 1][c2] - sum_map[r2][c1 - 1] + sum_map[r1 - 1][c1 - 1];
		cout << ans<<"\n";
	}


	return 0;
}
