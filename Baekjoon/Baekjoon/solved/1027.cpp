#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int N, cnt[51] = { 0, }, maximum;
ll hight[51];
bool flag;

int main() {
	cin >> N;

	flag = true;
	for (int i = 1; i <= N; i++)
		cin >> hight[i];

	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			for (int k = i + 1; k <= j - 1; k++) {
				if ((double)(hight[j] - hight[i]) / (j - i) * (k - i) + hight[i] <= hight[k]) {
					flag = false;
					break;
				}
			}
			if (flag == true) {
				cnt[i]++;
				cnt[j]++;
			}
			flag = true;

		}
	}
	maximum = cnt[0];
	for (int i = 1; i <= 50; i++)
		if (maximum < cnt[i])
			maximum = cnt[i];
	cout << maximum << endl;
	return 0;
}