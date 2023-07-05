#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	//백준 1253
	//투포인터

	int size = 0;
	int input_num;
	int cnt=0;

	vector<int> arr;
	
	//배열사이즈 입력
	cin >> size;
	//배열 입력
	for (int i = 0; i < size; i++) {
		cin >> input_num;
		arr.push_back(input_num);
	}
	// 투포인터 도입을 위한 소팅
	sort(arr.begin(), arr.end());

	for (int k = 0; k < size; k++) {
	
		int small_pointer = 0; // 왼쪽 포인터(작은쪽)
		int big_pointer = arr.size() - 1; // 오른쪽 포인터(큰쪽)
		int target = arr[k]; // 좋은 수 인지 체크할 대상 

		// 왼쪽 포인터가 오른쪽 포인터를 만나는 경우: 체크를 마침 -> 종료-> k값++
		while (small_pointer < big_pointer) {
			if ((arr[small_pointer] + arr[big_pointer]) == target) {
				// 왼쪽 포인터 와 오른쪽 포인터 모두 자기 자신을 가르치면 안됨, 좋은 수 조건 위배
				if(small_pointer != k && big_pointer !=k){
					cnt++;
					break;
				}
				// 대상인 k가 두 포인터 중 하나와 만나면 좋은 수 조건 위배 이므로, 
				//종료시키기 위해 왼쪽 포인터는 오른쪽으로
				//오른쪽 포인터는 왼쪽으로 넘겨버림
				else if (small_pointer == k) {
					small_pointer++;
				}

				else if (big_pointer == k) {
					big_pointer--;
				}
			}

			else if ((arr[small_pointer] + arr[big_pointer]) > target) {
				big_pointer-- ;
			}

			else if (((arr[small_pointer] + arr[big_pointer]) < target)) {
				small_pointer++ ;
			}
		}

	}

	cout << cnt;

	return 0;
}
