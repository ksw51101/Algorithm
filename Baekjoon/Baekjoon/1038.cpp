#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int n, maximum = 0, arr[10][10];

int main() {
	cin >> n;
	n++;
	for (int i = 0; i < 10; i++) {
		arr[0][i] = 1;
		maximum += arr[0][i];
	}
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j - 1];
			maximum += arr[i][j];
		}
	}
	if (maximum < n)
		cout << -1 << '\n';
	else {
		long long ans = 0;
		bool flag = false;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (n - arr[i][j] > 0)
					n -= arr[i][j];
				else {
					flag = true;
					ans += pow(10, i) * j;
					i--;
					j--;
					if (i < 0)
						break;
					while (n != 0) {
						for (int k = 0; k <= j; k++) {
							if (n - arr[i][k] >= 0) {
								n -= arr[i][k];
								if (n == 0) {
									for (int z = i; z >= 0; z--) {
										ans += pow(10, z) * k;
										k--;
									}
									break;
								}
							}
							else {
								ans += pow(10, i) * k;
								i--;
								j--;
								break;
							}
						}
					}
					break;
				}
			}
			if (flag)
				break;
		}
		cout << ans << '\n';
	}

	return 0;
}