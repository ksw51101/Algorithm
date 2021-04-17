#include <iostream>
using namespace std;

int n, cnt_2 = 0, cnt_5 = 0;
int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int num = i;
		while (1) {
			if (num % 2 == 0) {
				num /= 2;
				cnt_2++;
				continue;
			}
			else if (num % 5 == 0) {
				num /= 5;
				cnt_5++;
				continue;
			}
			else
				break;
		}
	}

	if (cnt_2 >= cnt_5)
		cout << cnt_5 << '\n';
	else
		cout << cnt_2 << '\n';

	return 0;
}