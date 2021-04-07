#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000];
void quick(int left, int right,int *arr);

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	random_shuffle(arr, arr + n);
	quick(0, n - 1, arr);

	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';

	return 0;
}

void quick(int left, int right, int *arr) {
	if (left >= right)
		return;
	int pivot = arr[left];
	int less = left + 1;
	int more = right;
	while (less <= more) {
		while (less <= more && arr[less] <= pivot)
			less++;
		while (less <= more && arr[more] >= pivot)
			more--;
		if (less < more)
			swap(arr[less], arr[more]);
	}
	swap(arr[more], arr[left]);
	quick(left, more - 1, arr);
	quick(more + 1, right, arr);

}