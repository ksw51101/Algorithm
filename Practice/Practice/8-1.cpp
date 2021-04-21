#include <iostream>
#include <algorithm>
using namespace std;

int x, arr[30001];

int main() {
	cin >> x;

	arr[1] = 0;
	for (int i = 2; i <= x; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 5 == 0)
			arr[i] = min(arr[i], arr[i / 5] + 1);
		if (i % 3 == 0)
			arr[i] = min(arr[i], arr[i / 3] + 1);
		if(i%2==0)
			arr[i] = min(arr[i], arr[i / 2] + 1);
	}
	cout << arr[x] << '\n';

	return 0;
}