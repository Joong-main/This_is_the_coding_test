#include<iostream>
#include<vector>

using namespace std;
int main(void) {
	
	int size;
	int input_num;
	int front;
	int rear;
	cin >> size;

	// 배열 입력부
	vector <int> arr;

	for (int i = 0; i < size; i++) {
		cin >> input_num;
		arr.push_back(input_num);
	}

	// 초기 배열 출력부
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "<- 초기 배열\n";

	// 구간에서 스왑이 필요없는 (이미 정렬이 되어있는) 상태면 브레이크
	bool swapped = false;

	// i:4 -> 0
	for (int i = size-1; i >= 0; i--) {
		swapped = false;
		// j:0-> 3,2,1,0
		for (int j = 0; j < i; j++) {
			front = j;
			rear = j + 1;

			if (arr[front] > arr[rear]) {
				swap(arr[rear], arr[front]);
				swapped = true;
			}

		}

		if (swapped == false) {
			cout << "정렬을 할 필요가 없는 배열 입니다.\n";
			break;

		}
	}

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "<- 정렬 배열\n";


	return 0;
}
