#include <iostream>
#include <vector>

using namespace std;


int Partition(vector<int> &arr, int start, int end) {
	int pivot = arr[end];
	int i;
	int index = start;
	int temp;

	for (i = start; i < end; i++) {
		if (arr[i] <= pivot) {
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
			index++;
		}
	}

	temp = arr[index];
	arr[index] = arr[end];
	arr[end] = temp;

	return index;

}

void QuickSort(vector<int> &arr, int start, int end) {

	int index;

	if (start < end) {
		index = Partition(arr, start, end);
		QuickSort(arr, start, index - 1);
		QuickSort(arr, index + 1, end);
	}

	else {
		return;
	}

}

int main(void) {

	vector<int> arr = {5,4,3,2,1};

	QuickSort(arr, 0,4);

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
