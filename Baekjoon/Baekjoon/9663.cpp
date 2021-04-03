#include <iostream>
using namespace std;

bool d_u[30] = { false, }, u_d[30] = { false, }, colm[17] = { false, };
int cnt = 0, n;

void start(int x, int n);
bool check(int x, int y);

void start(int x, int num) {
	if (num == n) {
		cnt++;
	}
	else {
		for (int j = 0; j < n; j++) {
			if (check(x, j)) {
				u_d[x + n - j - 1] = d_u[x + j] = colm[j] = true;
				start(x + 1, num + 1);
				u_d[x + n - j - 1] = d_u[x + j] = colm[j] = false;
			}
		}
	}
}

bool check(int x, int y) {
	if(colm[y] == true || u_d[x + n - y - 1] == true || d_u[x + y] == true)
		return false;
	return true;
}

int main() {
	cin >> n;

	start(0, 0);

	cout << cnt << '\n';

	return 0;
}