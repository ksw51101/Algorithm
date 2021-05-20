#include <iostream>
#include <string>
using namespace std;

int n;
char arr[64][64];
string str;

int check(int x, int y, int len) {
	char temp = arr[x][y];
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (arr[x + i][y + j] != temp) {
				return -1;
			}
		}
	}
	if (temp == '1')
		return 1;
	else
		return 0;
}
void start(int x, int y, int len) {
	if (len == 1) {
		if (arr[x][y] == '1')
			str += '1';
		else
			str += '0';
		return;
	}
	if (check(x, y, len) == -1) {
		int temp = len / 2;
		str += '(';
		start(x, y, temp);
		start(x, y + temp, temp);
		start(x + temp, y, temp);
		start(x + temp, y + temp, temp);
		str += ')';
	}
	else if (check(x, y, len) == 0) {
		str += '0';
	}
	else if (check(x, y, len) == 1) {
		str += '1';
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	start(0, 0, n);

	cout << str << '\n';

	return 0;
}