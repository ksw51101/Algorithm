#include <iostream>
#include <vector>
using namespace std;

int n, d, cnt;
vector<int> parent; // �θ� ��� ����
vector<bool> live; // ���� ���� ����

// ó�� �Է¹��� num���� Ʈ���� �Ž��� �ö� target�� ���� ��� true�� return�ϴ� �Լ�
bool find_target(int num, int target) {
	if (parent[num] == -1)
		return false;
	else if (parent[num] == target)
		return true;
	return find_target(parent[num], target);
}

// num�� ������ ������ ��带 �����ϴ� �Լ�
void delete_node(int num) {
	live[num] = false;
	for (int i = 0; i < n; i++) {
		if (find_target(i, num))
			live[i] = false;
	}
}

// leaf ��带 count�ϴ� �Լ�
void find_leaf() {
	vector<bool> node = live;
	for (int i = 0; i < n; i++) {
		if (!live[i])
			continue;
		int p = parent[i];
		if (p == -1)
			continue;
		node[p] = false;
	}
	for (int i = 0; i < n; i++)
		if (node[i])
			cnt++;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		parent.push_back(temp);
		live.push_back(true);
	}
	cin >> d;

	delete_node(d);
	find_leaf();

	cout << cnt << '\n';

	return 0;
}