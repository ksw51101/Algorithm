#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m, num[100], ans;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j)
				continue;
			else
				for (int k = 0; k < n; k++) {
					if (k == i || k == j)
						continue;
					else if(num[i]+num[j]+num[k]<=m){
						ans = max(num[i] + num[j] + num[k], ans);
					}
				}

	cout << ans << endl;

	return 0;
}