#include <iostream>
#include <cmath>
using namespace std;

int s, N, K, R1, R2, C1, C2;

int solution(int x, int y, int len) {
	if (len == 1) return 0; // ���̰� 1�̸� ���
	int b = len / N; // N���� ���� �簢���� ����

	if (x >= b * (N - K) / 2 && x < b * ((N - K) / 2 + K) && y >= b * (N - K) / 2 && y < b * ((N - K) / 2 + K)) // ��� K*K �簢���̸� ������
		return 1;

	return solution(x % b, y % b, b); // �ƴϸ� �ش� �簢���� ���Ͽ� ���ȣ��
}

int main() {
	cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

	int len = pow(N, s); // ��ü ����

	for (int i = R1; i <= R2; i++) {
		for (int j = C1; j <= C2; j++) {
			cout << solution(i, j, len); // ����ϰ��� �ϴ� �� �ȼ� Ȯ��
		}
		cout << '\n';
	}

	return 0;
}