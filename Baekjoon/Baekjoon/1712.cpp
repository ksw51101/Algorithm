#include <iostream>
using namespace std;

int main() {
	int A, B, C;

	cin >> A >> B >> C;

	if (C - B != 0) {
		if (A / (double)(C - B) + 1 > 0)
			cout << (int)(A / (double)(C - B) + 1) << endl;
		else
			cout << -1 << endl;
	}
	else
		cout << -1 << endl;

	return 0;
}