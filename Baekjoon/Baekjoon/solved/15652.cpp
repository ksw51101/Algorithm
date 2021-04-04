#include <iostream>
using namespace std;

int m, n, arr[8] = { 0, };

void start(int num) {
	if (num == n) {
		for (int i = 0; i < n; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= m; i++) {
		if (num == 0) {
			arr[num] = i;
			start(num + 1);
		}
		else if (i >= arr[num - 1]) {
			arr[num] = i;
			start(num + 1);
		}
	}

}

int main() {
	cin >> m >> n;

	start(0);

	return 0;
}