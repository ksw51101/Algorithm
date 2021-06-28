#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000000000 // min ����� ���� MAX�� ����

long long ans = 0, N, Min[3]; // Min[0] -> �ֻ��� 1���� �ּҰ�, Min[1] -> �ֻ��� 2�� ���� �ּҰ�, Min[2] -> �ֻ��� 3�� ���� �ּҰ�
vector<int> vec; // �ֻ��� 6���� ���� ������ vector
bool selected[6]; // �ֻ����� ���� ���õ��� Ȯ���ϴ� �迭

// �ֻ����� �ݴ��� ���� ���õǾ����� Ȯ���ϴ� �Լ�
bool check(int num) {
	if (selected[5 - num])
		return true;
	return false;
}

// Min�� DFS�� ���ϴ� �Լ�
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
	one = (N - 2) * (N - 2) * 5 + 4 * (N - 2); // n^3�� ������ü���� 1���� ���̴� �ֻ����� ����
	two = (N - 2) * 8 + 4; // n^3�� ������ü���� 2���� ���̴� �ֻ����� ����
	three = 4; // n^3�� ������ü���� 3���� ���̴� �ֻ����� ����

	if (N == 1) { // ����ó��
		sort(vec.begin(), vec.end());
		for (int i = 0; i < 5; i++)
			ans += vec[i];
	}
	else 
		ans = one * Min[0] + two* Min[1] + three * Min[2];
	
	cout << ans << '\n';
	return 0;
}