#include <iostream>
#include<vector>

using namespace std;

void merge(vector<int>& arr, int low, int mid,int high) {

	vector<int> arr_instance;
	int i = low;
	int j = mid + 1;
	int k = 0;

	while (i <=mid && j<=high)
	{
		if (arr[i] <= arr[j]) {
			arr_instance.push_back(arr[i]);
			i++;
			k++;
		
		}
		else {
			arr_instance.push_back(arr[j]);
			j++;
			k++;
		}
	}

	while (i <= mid) {
		arr_instance.push_back(arr[i]);
		i++;
		k++;
	}

	while (j <= high) {
		arr_instance.push_back(arr[j]);
		j++;
		k++;
	}

	k--;

	while (k >= 0) {
		arr[low + k] = arr_instance[k];
		k--;
	}

}


void mergeSort(vector<int>& arr, int low, int high) { 

	if (low < high) {
		int m = (low + high) / 2;
		mergeSort(arr, low, m);
		mergeSort(arr, m + 1, high);
		merge(arr, low, m, high);
	}
	else {
		return;
	}
}

int main(void) {

	vector<int> arr = { 50,40,30,20,10 };

	mergeSort(arr, 0, arr.size() - 1);

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}

	return 0;

}
