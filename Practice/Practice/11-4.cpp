#include <iostream>
#include <algorithm>
using namespace std;

int n, money[1000], sum = 1, index = 0;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> money[i];
	sort(money, money + n);

	while (money[index] <= sum) {
		sum += money[index];
		index++;
	}
	
	cout << sum << '\n';

	return 0;
}