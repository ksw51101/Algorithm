#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

double x[3], y[3], len[3];

int main() {
	for (int i = 0; i < 3; i++) 
		cin >> x[i] >> y[i];

	if ((x[0] == x[1] && x[1] == x[2]) || (y[0] == y[1] && y[1] == y[2])) // �� ���� x���� ���ų� y���� ���� ��� ������ �� �����Ƿ� -1 ���
		cout << -1 << '\n';
	else if ((y[0] - y[1]) / (x[0] - x[1]) == (y[0] - y[2]) / (x[0] - x[2])) // ���Ⱑ ���� ��� ������ �� �����Ƿ� -1 ���
		cout << -1 << '\n';
	else {
		cout.precision(16);

		len[0] = sqrt(pow(x[0] - x[1], 2) + pow(y[0] - y[1], 2));
		len[1] = sqrt(pow(x[1] - x[2], 2) + pow(y[1] - y[2], 2));
		len[2] = sqrt(pow(x[0] - x[2], 2) + pow(y[0] - y[2], 2));

		sort(len, len + 3); // �������� ����

		cout << 2 * (len[2] - len[0]) << '\n'; // �� �� ������ ���̸� ������������ a, b, c ��� ���� �� ���� ((b+c)-(a+b))*2
	}

	return 0;
}