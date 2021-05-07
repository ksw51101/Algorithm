#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, index_2 = 0, index_3 = 0, index_5 = 0;
	int arr[1000];
	cin >> n;

	arr[0] = 1;
	for (int i = 1; i < n; i++) {
		arr[i] = min(arr[index_2] * 2, min(arr[index_3] * 3, arr[index_5] * 5));
		if (arr[i] == arr[index_2] * 2) {
			index_2++;
		}
		if (arr[i] == arr[index_3] * 3) {
			index_3++;
		}
		if (arr[i] == arr[index_5] * 5) {
			index_5++;
		}
	}
	cout << arr[n - 1] << '\n';

	return 0;
}
