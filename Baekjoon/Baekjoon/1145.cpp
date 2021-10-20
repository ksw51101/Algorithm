#include <iostream>
using namespace std;

int num[5];

int main() {
	for (int i = 0; i < 5; i++) {
		cin >> num[i];
	}
	
	int i = 1;
	while(1) { // 1부터 증가하며 5개의 수로 나눈 후 3개 이상으로 나누어 떨어지는지 확인
		int cnt = 0;
		for (int j = 0; j < 5; j++) {
			if (i % num[j] == 0)
				cnt++;
		}
		if (cnt >= 3) {
			cout << i << '\n';
			break;
		}
		i++;
	}

	return 0;
}