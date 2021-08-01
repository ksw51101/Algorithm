#include <iostream>
#include <string>
using namespace std;

int n, cnt = 0;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		string temp = to_string(i);

		if (temp.size() == 1 || temp.size() == 2) { // 한 자리 수 또는 두 자리 수일 경우 항상 등차수열
			cnt++;
			continue;
		}
		int gap = temp[0] - temp[1]; // 제일 앞자리 수와 그 다음 수의 차이를 gap으로 설정
		for (int j = 1; j < temp.size(); j++) {
			if (j == temp.size() - 1) // 제일 끝자리 수까지 차이가 모두 같으므로 등차수열
				cnt++;
			else if (temp[j] - temp[j + 1] != gap) // 두 수의 차와 gap이 다를 경우 등차수열x
				break;
		}
	}
	cout << cnt << '\n';
		
	return 0;
}