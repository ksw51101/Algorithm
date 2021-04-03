#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T, x1, y1, x2, y2, n, cx[50], cy[50], r[50];

	cin >> T;
	for (int k = 0; k < T; k++) {
		int num = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> cx[i] >> cy[i] >> r[i];
		}
		for (int j = 0; j < n; j++) {
			if ((pow(x1 - cx[j], 2) + pow(y1 - cy[j], 2) < pow(r[j], 2) && pow(x2 - cx[j], 2) + pow(y2 - cy[j], 2) >= pow(r[j], 2)) ||
				(pow(x1 - cx[j], 2) + pow(y1 - cy[j], 2) >= pow(r[j], 2) && pow(x2 - cx[j], 2) + pow(y2 - cy[j], 2) < pow(r[j], 2))) {
				num++;
			}

		}
		cout << num << endl;
	}
	return 0;
}