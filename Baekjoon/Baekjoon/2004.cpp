#include <iostream>
#include <algorithm>
using namespace std;

int n, m, cnt_2 = 0, cnt_5 = 0;

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int num = i;
		while (1) {
			if (num % 2 == 0) {
				cnt_2++;
				num /= 2;
				continue;
			}
			else if (num % 5 == 0) {
				cnt_5++;
				num /= 5;
				continue;
			}
			else
				break;
		}
	}
	for (int i = 1; i <= m; i++) {
		int num = i;
		while (1) {
			if (num % 2 == 0) {
				cnt_2--;
				num /= 2;
				continue;
			}
			else if (num % 5 == 0) {
				cnt_5--;
				num /= 5;
				continue;
			}
			else
				break;
		}
	}
	for (int i = 1; i <= n - m; i++) {
		int num = i;
		while (1) {
			if (num % 2 == 0) {
				cnt_2--;
				num /= 2;
				continue;
			}
			else if (num % 5 == 0) {
				cnt_5--;
				num /= 5;
				continue;
			}
			else
				break;
		}
	}

	cout << min(cnt_2, cnt_5) << '\n';
	
	return 0;
}