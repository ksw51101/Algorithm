#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

// �������� sort�� ����� compare�Լ�
bool compare(int a, int b) {
	return a > b;
}

int main() {
	int ans = 0; // ��� ȭ���� �ű�µ� �ɸ��� �ּ� �ð�
	cin >> n;
	vector<int> limit(n); // ũ������ ���� ����
	vector<int> p(n); // �� ũ������ �� �� �ִ� ȭ���� ��(limit�� ���� ũ���κ��� �����ؼ� �̹� ���Ե� ȭ���� �����ϰ� count)
	for (int i = 0; i < n; i++)
		cin >> limit[i];
	cin >> m;
	vector<int> weight(m); // �� ȭ���� ����
	for (int i = 0; i < m; i++)
		cin >> weight[i];
	sort(limit.begin(), limit.end()); // �������� ����
	sort(weight.begin(), weight.end(), compare); // �������� ����
	if (limit.back() < weight.front()) // �ִ� ���Ը� �� �� �ִ� ũ������ ���� ���ſ� ȭ���� �� �� ���ٸ� -1 ���
		cout << -1 << '\n';
	else {
		// �� ũ������ �� �� �ִ� ȭ���� �� Ȯ��
		for (int i = 0; i < n; i++) {
			for (int j = weight.size() - 1; j >= 0; j--) {
				if (limit[i] >= weight[j]) {
					p[i]++;
					weight.pop_back();
				}
				else
					break;
			}
		}
		while (m > 0) { // ���� ������ ���� ������ �ݺ�
			ans++; // �ð� ���
			for (int i = n - 1; i >= 0; i--) { // ���� ���ſ� ȭ���� �� �� �ִ� ũ���κ��� ���� ������ ���Ը� �� �� �ִ� ũ���α��� Ȯ��
				if (p[i] > 0) { // �ش� ũ������ ȭ���� ������
					p[i]--; // �ش� ȭ�� �̵�
					m--; // ���� ȭ�� �� -1
				}
				else { // �ش� ũ������ �� ȭ���� ������
					for (int j = i - 1; j >= 0; j--) { // �� ���� ���Ը� �� �� �ִ� ũ������ ȭ���� ��� �Ű���
						if (p[j] > 0) {
							p[j]--;
							m--;
							break;
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}