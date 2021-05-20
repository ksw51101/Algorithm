#include <iostream>
using namespace std;

int n, arr[2200][2200], cnt1 = 0, cnt2 = 0, cnt3 = 0;

int check(int x, int y, int len) {
	int temp = arr[x][y];
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			if (arr[x + i][y + j] != temp)
				return 2;
	if (temp == -1)
		return -1;
	else if (temp == 0)
		return 0;
	else if (temp == 1)
		return 1;
}

void start(int x, int y, int len) {
	int result = check(x, y, len);
	if (result == -1)
		cnt1++;
	else if (result == 0)
		cnt2++;
	else if (result == 1)
		cnt3++;
	else {
		int temp = len / 3;
		for (int i = x; i < x + len; i += temp)
			for (int j = y; j < y + len; j += temp)
				start(i, j, temp);
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	start(0, 0, n);

	cout << cnt1 << '\n';
	cout << cnt2 << '\n';
	cout << cnt3 << '\n';

	return 0;
}