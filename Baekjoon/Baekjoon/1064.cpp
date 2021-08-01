#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

double x[3], y[3], len[3];

int main() {
	for (int i = 0; i < 3; i++) 
		cin >> x[i] >> y[i];

	if ((x[0] == x[1] && x[1] == x[2]) || (y[0] == y[1] && y[1] == y[2])) // 세 점의 x값이 같거나 y값이 같을 경우 일직선 상에 있으므로 -1 출력
		cout << -1 << '\n';
	else if ((y[0] - y[1]) / (x[0] - x[1]) == (y[0] - y[2]) / (x[0] - x[2])) // 기울기가 같을 경우 일직선 상에 있으므로 -1 출력
		cout << -1 << '\n';
	else {
		cout.precision(16);

		len[0] = sqrt(pow(x[0] - x[1], 2) + pow(y[0] - y[1], 2));
		len[1] = sqrt(pow(x[1] - x[2], 2) + pow(y[1] - y[2], 2));
		len[2] = sqrt(pow(x[0] - x[2], 2) + pow(y[0] - y[2], 2));

		sort(len, len + 3); // 오름차순 정렬

		cout << 2 * (len[2] - len[0]) << '\n'; // 두 점 사이의 길이를 오름차순으로 a, b, c 라고 했을 때 답은 ((b+c)-(a+b))*2
	}

	return 0;
}