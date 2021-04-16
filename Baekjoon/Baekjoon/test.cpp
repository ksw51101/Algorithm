#include <iostream>
#include <algorithm>
using namespace std;

int n, m[100];
bool flag;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> m[i];
	sort(m, m + n);
	for (int i = 2; i <= sqrt(m[n - 1]); i++) {
		flag = false;
		int r = m[0] % i;
		for (int j = 1; j < n; j++) {
			if (m[j] % i != r) {
				flag = true;
				break;
			}
		}
		if (flag == false)
			cout << i << ' ';
	}


	return 0;
}