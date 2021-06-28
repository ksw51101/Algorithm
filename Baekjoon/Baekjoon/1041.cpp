#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000000000 // min 계산을 위한 MAX값 설정

long long ans = 0, N, Min[3]; // Min[0] -> 주사위 1면의 최소값, Min[1] -> 주사위 2면 합의 최소값, Min[2] -> 주사위 3면 합의 최소값
vector<int> vec; // 주사위 6면의 값을 저장할 vector
bool selected[6]; // 주사위의 면이 선택된지 확인하는 배열

// 주사위의 반대쪽 면이 선택되었는지 확인하는 함수
bool check(int num) {
	if (selected[5 - num])
		return true;
	return false;
}

// Min을 DFS로 구하는 함수
void getNum(int n, int sum) {
	if (n == 1) {
		Min[0] = min(Min[0], (long long)sum);
	}
	if (n == 2) {
		Min[1] = min(Min[1], (long long)sum);
	}
	if (n == 3) {
		Min[2] = min(Min[2], (long long)sum);
		return;
	}
	for (int i = 0; i < 6; i++) {
		if (!selected[i] && !check(i)) {
			selected[i] = true;
			sum += vec[i];
			getNum(n + 1, sum);
			selected[i] = false;
			sum -= vec[i];
		}
	}
}

int main() {
	cin >> N;
	fill(&Min[0], &Min[3], MAX);
	for (int i = 0; i < 6; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	getNum(0, 0);
	
	long long one, two, three;
	one = (N - 2) * (N - 2) * 5 + 4 * (N - 2); // n^3의 정육면체에서 1면이 보이는 주사위의 개수
	two = (N - 2) * 8 + 4; // n^3의 정육면체에서 2면이 보이는 주사위의 개수
	three = 4; // n^3의 정육면체에서 3면이 보이는 주사위의 개수

	if (N == 1) { // 예외처리
		sort(vec.begin(), vec.end());
		for (int i = 0; i < 5; i++)
			ans += vec[i];
	}
	else 
		ans = one * Min[0] + two* Min[1] + three * Min[2];
	
	cout << ans << '\n';
	return 0;
}