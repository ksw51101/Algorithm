#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	int num[3], maximum;

	while (1) {
		for (int i = 0; i < 3; i++)
			cin >> num[i];
		if (num[0] == 0 && num[1] == 0 && num[2] == 0)
			break;
		sort(num, num + 3);
		if (pow(num[2], 2) == pow(num[0], 2) + pow(num[1], 2))
			cout << "right" << endl;
		else
			cout << "wrong" << endl;

	}
	return 0;
}