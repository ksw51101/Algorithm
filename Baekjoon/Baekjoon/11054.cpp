#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[1000], len_left[1000] = { 0, }, len_right[1000] = { 0, };

void start(int num) {
	if (num > n) {
		int max_num = 0;
		for (int i = 0; i < n; i++)
			max_num = max(max_num, len_left[i] + len_right[i] + 1);
		cout << max_num << '\n';
		return;
	}

	for (int i = 0; i < num; i++) {
		if (arr[num] > arr[i])
			len_left[num] = max(len_left[i] + 1, len_left[num]);
		if (arr[n - 1 - num] > arr[n - 1 - i])
			len_right[n - 1 - num] = max(len_right[n - 1 - i] + 1, len_right[n - 1 - num]);
	}
	start(num + 1);
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	len_left[0] = len_right[n - 1] = 0;
	start(1);

	return 0;
}