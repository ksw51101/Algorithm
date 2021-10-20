#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {
	cin >> n;
	vector<int> vec(n, 0); // 위치별 앉은 사람을 저장하는 변수

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		for (int j = 0; j < n; j++) {
			if (vec[j] == 0 && temp == 0) { // 빈자리이고 왼쪽에 자신보다 큰 사람이 없다면
				vec[j] = i + 1; // 착석
				break;
			}
			if (vec[j] == 0) // 빈자리일 경우 왼쪽에 앉은 사람 수 -1
				temp--;
		}
	}

	for (int i = 0; i < n; i++)
		cout << vec[i] << ' ';
	cout << '\n';

	return 0;
}