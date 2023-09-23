#include<iostream>
#include<vector>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	long res = 0;
	cin >> N >> M;

	
	vector<long> sum_arr(N,0);
	vector<long> cnt(M,0);

	cin >> sum_arr[0];

	for (int i = 1; i < N; i++) {
		int temp = 0;
		cin >> temp;
		sum_arr[i] = sum_arr[i - 1] + temp;
	}



	for (int i = 0; i < N; i++) {
		long rest = sum_arr[i] % M;

		if (rest == 0) {
			res++;
		}
		cnt[rest]++;

	}


	for (int i = 0; i < M; i++) {
		if (cnt[i] > 1) {
			res = res + ((cnt[i] * (cnt[i] - 1) / 2));
		}
	}

	cout << res<<"\n";

	return 0;
}
