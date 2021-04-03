#include <iostream>
using namespace std;

int main() {
	int A;
	char B[3];

	cin >> A >> B[0] >> B[1] >> B[2];

	cout << A * (B[2] - '0') << endl;
	cout << A * (B[1] - '0') << endl;
	cout << A * (B[0] - '0') << endl;

	cout << A * ((B[0] - '0') * 100 + (B[1] - '0') * 10 + (B[2] - '0'));
	return 0;
}