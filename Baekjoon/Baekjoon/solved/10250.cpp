#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int T, H, W, N, level;
string room_num;

int main() {

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;

		room_num = to_string((int)ceil(N / (double)H));
		if (room_num.length() == 1)
			room_num = '0' + room_num;
		level = N % H;
		if (level == 0)
			level = H;

		cout << level << room_num << endl;
	}

	return 0;
}