#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<int> vec;

// 주어진 규칙 a, b로 모든 수가 나올 수 있는지 확인하는 함수
bool check(int a, int b) {
	for (int i = 0; i < n - 1; i++) {
		if (vec[i] * a + b != vec[i + 1])
			return false;
	}
	return true;
}

// a를 기울기, b를 y절편으로 갖는 직선이라고 생각하고 이를 구해 답을 찾는 함수
void solution() {
	int a;
	if (vec[1] == vec[0])
		a = 0;
	else
		a = (vec[2] - vec[1]) / (vec[1] - vec[0]);
	int b = vec[1] - vec[0] * a;
	if (check(a, b)) // 모두 같은 직선 위에 있는 경우
		cout << vec[n - 1] * a + b;
	else
		cout << 'B' << '\n';
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		vec.emplace_back(temp);
	}

	if (n == 1) cout << 'A' << '\n'; // 수가 1개이면 두 번째에 모든 수가 나올 수 있으므로 'A'출력
	else if (n == 2) {
		if (vec[0] == vec[1]) cout << vec[0] << '\n'; // 첫 번째 수와 두 번째 수가 같으면 세 번째부터도 같은 수가 나와야 한다.
		else cout << 'A' << '\n'; // 수가 2개이고 두 수가 다를 경우 a=0, a=1 등 여러 수가 나올 수 있다.
	}
	else solution();

	return 0;
}