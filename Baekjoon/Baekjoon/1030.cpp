#include <iostream>
#include <cmath>
using namespace std;

int s, N, K, R1, R2, C1, C2;

int solution(int x, int y, int len) {
	if (len == 1) return 0; // 길이가 1이면 흰색
	int b = len / N; // N개로 나뉜 사각형의 길이

	if (x >= b * (N - K) / 2 && x < b * ((N - K) / 2 + K) && y >= b * (N - K) / 2 && y < b * ((N - K) / 2 + K)) // 가운데 K*K 사각형이면 검정색
		return 1;

	return solution(x % b, y % b, b); // 아니면 해당 사각형에 대하여 재귀호출
}

int main() {
	cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

	int len = pow(N, s); // 전체 길이

	for (int i = R1; i <= R2; i++) {
		for (int j = C1; j <= C2; j++) {
			cout << solution(i, j, len); // 출력하고자 하는 각 픽셀 확인
		}
		cout << '\n';
	}

	return 0;
}