#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

static int N;

bool is_prime(int num) {
	for (int i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

void DFS(int num, int size) {

	if (size == N) {
		if (is_prime(num) == true) {
			cout << num<<"\n";
		}
		return;
	}


	for (int i = 1; i < 10; i++) {

		if (i % 2 == 0) {
			continue;
		}

		if (is_prime(num * 10 + i)) {
			DFS(num * 10 + i, size + 1);
		}
	}
}



int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);

	return 0;
}
