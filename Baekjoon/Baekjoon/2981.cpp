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
	for (int i = 2; i <= m[n - 1]; i++) {
		flag = false;
		for (int j = 0; j < n; j++) {
			if (m[j] % i != 0) {
				flag = true;
				continue;
			}
		}
		if (flag == false)
			cout << i << ' ';
	}


	return 0;
}