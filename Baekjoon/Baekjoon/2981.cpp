#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, m[100], k;
vector<int> vec;
bool flag;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> m[i];
	sort(m, m + n);
	k = m[n - 1] - m[n - 2];
	vec.push_back(k);

	for (int i = 2; i <= sqrt(k); i++) {
		if (k % i == 0) {
			vec.push_back(i);
			if (i != k / i)
				vec.push_back(k / i);
		}
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		flag = false;
		int r = m[0] % vec[i];
		for (int j = 1; j < n; j++) {
			if (m[j] % vec[i] != r) {
				flag = true;
				break;
			}
		}
		if (flag == false)
			cout << vec[i] << ' ';
	}

	return 0;
}