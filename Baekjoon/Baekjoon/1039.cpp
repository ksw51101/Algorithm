#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int k, ans = 0;;
string n;
queue<pair<string, int>> q;
bool visited[1000001][11];

int main() {
	cin >> n >> k;

	q.push({ n, k });

	while (!q.empty()) {
		string temp = q.front().first; // ��
		int num = q.front().second; // ���� ���� ��
		q.pop();
		if (num == 0) { // k�� ��ŭ�� ������ ���� ���
			ans = max(ans, stoi(temp)); // ans ����
			continue;
		}

		for (int i = 0; i < temp.size() - 1; i++) {
			for (int j = i + 1; j < temp.size(); j++) {
				swap(temp[i], temp[j]); // i��° �ڸ����� j��° �ڸ��� swap
				if (temp[0] == '0' || visited[stoi(temp)][num - 1] == true) { // swap�� ���� ù��° �ڸ����� 0�̰ų� �̹� ��������� ���� ��� �ٽ� swap
					swap(temp[i], temp[j]);
					continue;
				}
				visited[stoi(temp)][num - 1] = true; // �湮ó��
				q.push({ temp, num - 1 }); // q�� ����
				swap(temp[i], temp[j]); // ������� swap
			}
		}
	}
	if (ans == 0) // 1�ڸ� �� �Ǵ� 2�ڸ� �� �� 0���� ������ �� �� k����ŭ�� ������ �Ұ����� ���
		cout << -1 << '\n';
	else
		cout << ans << '\n';

	return 0;
}