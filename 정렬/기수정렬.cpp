#include <iostream>
#include <queue>
using namespace std;

void radixSort(vector <int> &arr, int n) {

    int max = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    // 최대 자리수를 구해낸다.
    int k = 1;
    while (max / 10) {
        k *= 10;
        max /= 10;
    }
    queue<int> queue[10];
    int digit = 1, mod = 10;
    while (digit <= k) {
        // 자리수에 맞게 Queue push
        for (int i = 0; i < n; i++) {
            queue[(arr[i] % mod) / digit].push(arr[i]);
        }
        // Queue에 들어가 있는 원소를 배열에 재배치
        int j = 0;
        for (int i = 0; i < 10; i++) {
            while (queue[i].size() > 0) {
                arr[j++] = queue[i].front();
                queue[i].pop();
            }
        }
        // 비교할 자릿수 변경
        digit *= 10; mod *= 10;
    }
}

int main(void) {
    int size = 10;
    vector<int> arr = { 100,90,80,70,60,50,40,30,20,10 };

    radixSort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

}
