#include <iostream>
using namespace std;

int n;
long long ans = 0, arr[100][10];

void start(int num) {
	if (num == n)
		return;
	arr[num][0] = arr[num - 1][1] % 1000000000;
	arr[num][9] = arr[num - 1][8] % 1000000000;
	for (int i = 1; i < 9; i++) {
		arr[num][i] = (arr[num - 1][i - 1] + arr[num - 1][i + 1]) % 1000000000;
	}
	start(num + 1);
}

int main() {
	cin >> n;

	arr[0][0] = 0;
	for (int i = 1; i <= 9; i++)
		arr[0][i] = 1;
	start(1);

	for (int i = 0; i < 10; i++)
		ans = (ans + arr[n - 1][i]) % 1000000000;

	cout << ans << '\n';
	return 0;
}