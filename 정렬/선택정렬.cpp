#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	vector<int> arr;
	int size;
	int input_num;
	int min_num;
	int min_index;
	int temp;

	// 배열 입력부
	cin >> size;

	for (int i = 0; i < size; i++) {
		cin >> input_num;
		arr.push_back(input_num);
	}

	for (int i = 0; i < size; i++) {
		min_num = arr[i]; //대상의 값을 최솟값이라 초기설정
		min_index = i; 
		for (int j = i; j < size; j++) {

			if (arr[j] < min_num) { // i번째 ~ 배열 끝까지 돌면서 최솟값 갱신
				min_num = arr[j];
				min_index = j;
			}
		}
		temp = arr[i]; // 최솟값과 대상의 값을 SWAP
		arr[i] = min_num;
		arr[min_index] = temp;
	}

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
