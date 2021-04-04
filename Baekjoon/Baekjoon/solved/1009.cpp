#include <iostream>
#include <cmath>
using namespace std;

int T, a, b, rest, c;

int main() {

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> a >> b;

		rest = a % 10;

		switch (rest) {
		case 0:
			c = 10;
			break;
		case 1:
			c = 1;
			break;
		case 2:
		case 3:
		case 7:
		case 8:
			b %= 4;
			if (b == 0)
				b = 4;
			c = pow(rest, b);
			c %= 10;
			break;
		case 4:
		case 9:
			b %= 2;
			if (b == 0)
				b = 2;
			c = pow(rest, b);
			c %= 10;
			break;
		case 5:
			c = 5;
			break;
		case 6:
			c = 6;
			break;			
		}
		cout << c << endl;
	}

	return 0;
}