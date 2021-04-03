#include <iostream>
using namespace std;

void bubble(int n, int* arr);

int main() {
	int n, arr[1000];

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	bubble(n, arr);

	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;

	return 0;
}

void bubble(int n, int *arr) {
	int min, temp, index;
	for (int i = 0; i < n - 1; i++) {
		index = i;
		min = arr[i];
		for (int j = i + 1; j < n; j++) {
			if (min > arr[j]) {
				min = arr[j];
				index = j;
			}
		}
		temp = arr[i];
		arr[i] = min;
		arr[index] = temp;
	}
}