#include <iostream>
#include <vector>
using namespace std;

int x;

// ���� ��� ������ ������ ���� return�ϴ� �Լ�
int check(vector<int>& vec) {
	int len = 0;
	for (int i = 0; i < vec.size(); i++)
		len += vec[i];
	return len;
}

// �ൿ 1��(���� ���� ���븦 ������ �ڸ��� �߸� ���� �� �ϳ��� ������ ��� ������ ���� x�� ���Ͽ� ũ�ų� ������ �߸� ���� �� �Ѱ��� ������)
void cut(vector<int>& vec) {
	int temp = vec.back() / 2;
	vec.pop_back();
	vec.push_back(temp);

	if (x > check(vec))
		vec.push_back(temp);
}

int main() {
	vector<int> vec;
	cin >> x;

	vec.push_back(64); // 64cm ���� �ϳ��� ��� ����

	while (check(vec) != x) // ������ ���� x�� ������ �ݺ� ����
		cut(vec);
	
	cout << vec.size() << '\n'; // ������ �� ���

	return 0;
}