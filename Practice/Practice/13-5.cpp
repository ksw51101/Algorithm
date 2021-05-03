#include <iostream>
#include <algorithm>
using namespace std;

int n, num[100], oper[4], maximum = -1000000000, minimum = 1000000000, ans;

void start(int index) {
	if (index >= n - 1) {
		maximum = max(maximum, ans);
		minimum = min(minimum, ans);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (oper[i] <= 0) 
			continue;
		oper[i]--;
		int temp = ans;
		switch (i) {
		case 0:
			ans += num[index + 1];
			break;
		case 1:
			ans -= num[index + 1];
			break;
		case 2:
			ans *= num[index + 1];
			break;
		case 3:
			ans /= num[index + 1];
			break;
		}
		start(index + 1);
		ans = temp;
		oper[i]++;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];

	ans = num[0];
	start(0);

	cout << maximum << '\n' << minimum << '\n';

	return 0;
}