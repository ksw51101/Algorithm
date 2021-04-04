#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include<iomanip>
using namespace std;

int r1, r2, c1, c2, arr[50][5] = { 0, }, num, dir, x, y, maximum, len, max_num;
double pp;
string str_max;

int main() {
	num = dir = 1;
	len = 0;
	cin >> r1 >> c1 >> r2 >> c2;
	maximum = max(abs(r1), abs(c1));
	maximum = max(maximum, abs(r2));
	maximum = max(maximum, abs(c2));
	maximum = pow(maximum * 2 + 1, 2);
	str_max = to_string(maximum);
	len = str_max.length();
	x = y = 0;
	

	if (x >= r1 && x <= r2 && y >= c1 && y <= c2) {
		arr[x - r1][y - c1] = num;
	}
	while (num <= maximum) {
		pp++;
		switch (dir) {
		case 1:
			for (int i = 1; i <= ceil(pp / 2); i++) {
				num++;
				y++;
				if (x >= r1 && x <= r2 && y >= c1 && y <= c2) {
					arr[x - r1][y - c1] = num;
					max_num = num;
				}
			}
			dir = 2;
			break;
		case 2:
			for (int i = 1; i <= ceil(pp / 2); i++) {
				num++;
				x--;
				if (x >= r1 && x <= r2 && y >= c1 && y <= c2) {
					arr[x - r1][y - c1] = num;
					max_num = num;
				}
			}
			dir = 3;
			break;
		case 3:
			for (int i = 1; i <= ceil(pp / 2); i++) {
				num++;
				y--;
				if (x >= r1 && x <= r2 && y >= c1 && y <= c2) {
					arr[x - r1][y - c1] = num;
					max_num = num;
				}
			}
			dir = 4;
			break;
		case 4:
			for (int i = 1; i <= ceil(pp / 2); i++) {
				num++;
				x++;
				if (x >= r1 && x <= r2 && y >= c1 && y <= c2) {
					arr[x - r1][y - c1] = num;
					max_num = num;
				}
			}
			dir = 1;
			break;
		}
	}

	len = to_string(max_num).length();
	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) {
			cout << setw(len) << arr[i][j];
			if (j != c2 - c1)
				cout << ' ';
		}

		if (i != r2 - r1)
			printf("\n");
	}

	return 0;
}