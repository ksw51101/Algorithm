#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<int> vec;

// �־��� ��Ģ a, b�� ��� ���� ���� �� �ִ��� Ȯ���ϴ� �Լ�
bool check(int a, int b) {
	for (int i = 0; i < n - 1; i++) {
		if (vec[i] * a + b != vec[i + 1])
			return false;
	}
	return true;
}

// a�� ����, b�� y�������� ���� �����̶�� �����ϰ� �̸� ���� ���� ã�� �Լ�
void solution() {
	int a;
	if (vec[1] == vec[0])
		a = 0;
	else
		a = (vec[2] - vec[1]) / (vec[1] - vec[0]);
	int b = vec[1] - vec[0] * a;
	if (check(a, b)) // ��� ���� ���� ���� �ִ� ���
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

	if (n == 1) cout << 'A' << '\n'; // ���� 1���̸� �� ��°�� ��� ���� ���� �� �����Ƿ� 'A'���
	else if (n == 2) {
		if (vec[0] == vec[1]) cout << vec[0] << '\n'; // ù ��° ���� �� ��° ���� ������ �� ��°���͵� ���� ���� ���;� �Ѵ�.
		else cout << 'A' << '\n'; // ���� 2���̰� �� ���� �ٸ� ��� a=0, a=1 �� ���� ���� ���� �� �ִ�.
	}
	else solution();

	return 0;
}