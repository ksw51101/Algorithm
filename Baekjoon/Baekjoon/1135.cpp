#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
vector<int> vec[50];

bool cmp(int a, int b) {
	return a > b;
}

int DFS(int num) {
	if (vec[num].empty()) // ���Ӻ��ϰ� ������ return 0
		return 0;

	vector<int> order(vec[num].size()); // ������������ �����ϱ� ���� vector

	for (int i = 0; i < vec[num].size(); i++) { // num�� ������ ��� ���Ӻ��Ͽ� ���� DFS ����
		order[i] = DFS(vec[num][i]);
	}
	sort(order.begin(), order.end(), cmp); // ������ �������� �����ϴµ� �ɸ��� �ð��� ������������ ����

	int ret = 0;
	for (int i = 0; i < order.size(); i++) // num�� ������ �޽��� ���� �ð� = (�����ϴ� ����(�ð�) + ���޴��� ������ �޽��� ���� �ð�)�� �ִ밪
		ret = max(ret, order[i] + i + 1);

	return ret;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (i == 0) // 0�������� �н�
			continue;
		vec[temp].emplace_back(i); // temp��° ������ ���Ӻ��Ͽ� i �߰�
	}

	cout << DFS(0) << '\n'; // �ֻ��� �������� ����

	return 0;
}