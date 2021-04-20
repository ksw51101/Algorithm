#include <iostream>
using namespace std;

int n, arr[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

int main() {
	n = 10;

	for (int i = 0; i < n - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		swap(arr[min_index], arr[i]);
	}

	for (auto i : arr)
		cout << i << ' ';

	return 0;
}