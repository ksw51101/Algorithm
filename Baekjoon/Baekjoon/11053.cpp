#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[1000], len[1000] = { 0, };

void start(int num) {
	if (num > n) {
		int max_num = 0;
		for (int i = 0; i < n; i++)
			max_num = max(max_num, len[i]);
		cout << max_num << '\n';
		return;
	}

	for (int i = 0; i < num; i++)
		if (arr[num] > arr[i])
			len[num] = max(len[i], len[num]);
	len[num]++;
	start(num + 1);
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	len[0] = 1;
	start(1);

	return 0;
}