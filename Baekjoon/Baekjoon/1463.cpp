#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[1000001];

void start(int num) {
	if (num > n)
		return;

	if (num % 2 == 0) {
		if (num % 3 == 0) {
			arr[num] = min(arr[num - 1], min(arr[num / 2], arr[num / 3])) + 1;
		}
		else
			arr[num] = min(arr[num / 2], arr[num - 1]) + 1;
	}
	else if (num % 3 == 0)
		arr[num] = min(arr[num / 3], arr[num - 1]) + 1;
	else
		arr[num] = arr[num - 1] + 1;

	start(num + 1);
}

int main() {
	cin >> n;

	arr[1] = 0;
	 
	start(2);

	cout << arr[n] << '\n';

	return 0;
}