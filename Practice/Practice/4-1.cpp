#include <iostream>
#include <string>
using namespace std;

int n, pos_x = 1, pos_y = 1;
char plan[100];

int main() {
	cin >> n;

	int i = 0;
	do {
		cin >> plan[i];
		i++;
	} while (getc(stdin) == ' ');

	for(int j=0;j<i;j++)
		switch (plan[j]) {
		case 'U':
			if (pos_y > 1)
				pos_y--;
			break;
		case 'D':
			if (pos_y < n)
				pos_y++;
			break;
		case 'L':
			if (pos_x > 1)
				pos_x--;
			break;
		case 'R':
			if (pos_x < n)
				pos_x++;
			break;
		}

	cout << pos_y << ' ' << pos_x << '\n';

	return 0;
}