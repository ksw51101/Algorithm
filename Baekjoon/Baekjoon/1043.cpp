#include <iostream>
#include <vector>
using namespace std;

int n, m, num, gnum = 0;
vector<int> truth; // ������ �ƴ� ���
vector<int> party[50]; // ��Ƽ�� �����ϴ� ���

// ������ �ƴ� ����� ���� �׷����� Ȯ���ϴ� �Լ�
bool check(int pnum, vector<int> &belonged) {
	for (int i = 0; i < truth.size(); i++) {
		if (belonged[pnum] == belonged[truth[i]])
			return true;
	}
	return false;
}

int main() {
	cin >> n >> m >> num;
	vector<int> belonged(n + 1, -1); // n��° ����� ���ϴ� �׷�

	for (int i = 0; i < num; i++) {
		int temp;
		cin >> temp;
		truth.push_back(temp);
	}

	for (int i = 0; i < m; i++) {
		int obj; // ��Ƽ�� �����ϴ� ù��° ���
		cin >> num;
		if (num) { // ��Ƽ�� 1�� �̻� ������ ���
			cin >> obj;
			party[i].push_back(obj); // i��° ��Ƽ�� obj��° ��� ����
			if (belonged[obj] == -1) // ù��° �����ڰ� �׷쿡 ������ ���� ��� �׷� ����, �Ҽ�
				belonged[obj] = gnum++;
		}
		for (int j = 1; j < num; j++) { // i��° ��Ƽ�� �����ϴ� ������ ����� ���Ͽ� �׷��� ���� ��� ù��° �����ڿ� ���� �׷쿡 �Ҽ�, �׷��� ���� ��� �ش� �׷�� ��� ù��° �����ڿ� ���� �׷����� ����
			int temp;
			cin >> temp;
			party[i].push_back(temp);
			if (belonged[temp] == -1)
				belonged[temp] = belonged[obj];
			else {
				int target = belonged[temp];
				for (int i = 1; i <= n; i++) {
					if (belonged[i] == target)
						belonged[i] = belonged[obj];
				}
			}
		}
	}
	int cnt = 0; // ������ �ƴ� ����� ���� ��Ƽ�� ��

	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= party[i].size(); j++) {
			if (j == party[i].size()) { // �� ��Ƽ���� ������ �ƴ� ����� �Ѹ� ���� ��� cnt++
				cnt++;
				break;
			}
			int pnum = party[i][j];
			if (check(pnum, belonged)) 
				break;
		}
	}
	cout << cnt << '\n';

	return 0;
}