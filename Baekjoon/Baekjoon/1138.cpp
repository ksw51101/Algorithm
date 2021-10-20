#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
	cin >> n;
	vector<int> vec(n, 0);

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		for (int j = 0; j < n; j++) {
			if (vec[j] == 0 && temp==0) {
				vec[j] = i + 1;
				break;
			}
			if (vec[j] == 0)
				temp--;
		}
	}

	for (int i = 0; i < n; i++)
		cout << vec[i] << ' ';
	cout << '\n';

	return 0;
}