#include <iostream>
using namespace std;

int arr[21][21][21] = { 0, };

int w(int i, int j, int k) {
	if (i <= 0 || j <= 0 || k <= 0)
		return 1;
	else if (i > 20 || j > 20 || k > 20)
		return w(20, 20, 20);

	if (arr[i][j][k] != 0)
		return arr[i][j][k];
	else {

		if (i < j && j < k)
			arr[i][j][k] = w(i, j, k - 1) + w(i, j - 1, k - 1) - w(i, j - 1, k);
		else
			arr[i][j][k] = w(i - 1, j, k) + w(i - 1, j - 1, k) + w(i - 1, j, k - 1) - w(i - 1, j - 1, k - 1);
	}
	return arr[i][j][k];
}

int main() {
	int a, b, c;

	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';

	}


	return 0;
}