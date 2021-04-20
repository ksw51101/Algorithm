#include <iostream>
using namespace std;

int n = 10;
int arr[10] = { 7, 0, 9, 0, 3, 1, 6, 2, 4, 8 };

void quick(int start, int finish) {
	if (start >= finish)
		return;
	int pivot = start;
	int left = start + 1, right = finish;
	while (left <= right) {
		while (arr[left] <= arr[pivot] && left <= finish)
			left++;
		while (arr[right] >= arr[pivot] && right >= start + 1)
			right--;
		if (left > right)
			swap(arr[pivot], arr[right]);
		else
			swap(arr[right], arr[left]);
	}
	quick(start, right - 1);
	quick(right + 1, finish);
}

int main() {

	quick(0, n-1);

	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';

	return 0;
}