#include<iostream>
#include<vector>

using namespace std;

static vector<int>value;


int find(int a) {
	if (a == value[a]) {
		return a;
	}
	else {
		return value[a] = find(value[a]);
	}
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		value[b] = a;
	}
}


bool check_same(int a, int b) {
	
	a = find(a);
	b = find(b);

	if (a == b) {
		return true;
	}

	else { 
		return false; 
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	// 초기화
	for (int i = 0; i < n+1; i++) {
		value.push_back(i);
	}

	for (int i = 0; i < m; i++) {
		int mode, a, b;
		cin >> mode >> a >> b;
		if (mode == 0) {
			uni(a, b);
		}
		else {
			bool res = check_same(a, b);
			if (res == true) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
		}
	}


	return 0;
}
