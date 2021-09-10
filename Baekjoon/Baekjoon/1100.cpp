#include <iostream>
using namespace std;

int main() {
	int cnt = 0; // 조건을 만족하는 말의 수

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			char temp;
			cin >> temp;
			if (temp == 'F' && !((i + j) % 2)) // 말이 놓여있고 행과 열의 합이 짝수이면 흰색칸이므로 cnt++
				cnt++;
		}
	cout << cnt << '\n';

	return 0;
}