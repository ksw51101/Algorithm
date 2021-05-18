#include <iostream>
using namespace std;

int n, arr[128][128], cnt_white = 0, cnt_blue = 0;

int check(int x, int y, int len) {
	int temp = arr[x][y];
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (arr[x + i][y + j] != temp) {
				return -1;
			}
		}
	}
	if (temp == 1)
		return 1;
	else
		return 0;
}

void start(int x, int y, int len) {
	if (len == 1) {
		if (arr[x][y] == 1)
			cnt_blue++;
		else
			cnt_white++;
		return;
	}
	if (check(x, y, len) == -1) {
		int temp = len / 2;
		start(x, y, temp);
		start(x + temp, y, temp);
		start(x, y + temp, temp);
		start(x + temp, y + temp, temp);
	}
	else if (check(x, y, len) == 0) {
		cnt_white++;
	}
	else if (check(x, y, len) == 1) {
		cnt_blue++;
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	start(0, 0, n);

	cout << cnt_white << "\n";
	cout << cnt_blue << "\n";

	return 0;
}