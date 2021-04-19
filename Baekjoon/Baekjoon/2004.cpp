#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;

int num_cnt(int num, int obj) {
	int cnt = 0, index = 0;
	while (!(num % obj == 0))
		num--;
	if (num != 0) 
		while (!(num >= pow(obj, index) && num < pow(obj, index + 1)))
			index++;
	
	for (int i = 1; i <= index; i++) {
		int r = pow(obj, i);
		cnt += num / r;
	}

	return cnt;
}

int main() {
	int a, b, c;
	cin >> n >> m;

	a = num_cnt(n, 2);
	b = num_cnt(n - m, 2);
	c = num_cnt(m, 2);
	cout << min(num_cnt(n, 2) - num_cnt(n - m, 2) - num_cnt(m, 2), num_cnt(n, 5) - num_cnt(n - m, 5) - num_cnt(m, 5)) << '\n';
	
	return 0;
}