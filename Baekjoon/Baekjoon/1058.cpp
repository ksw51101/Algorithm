#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100000000
int n;

// �÷��̵� ���� �˰���
void solution(vector<vector<int>> &a) {
	int size = a.size();

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
}

int main() {
	cin >> n;
	vector<vector<int>> vec(n, vector<int>(n, MAX)); // �ʱⰪ ���Ѵ�� �ʱ�ȭ
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			char temp;
			cin >> temp;
			if (i == j) // �ڽſ����� �Ÿ��� 0
				vec[i][j] = 0;
			if(temp=='Y') // ģ���� ��� �Ÿ��� 1
				vec[i][j] = 1;
		}

	solution(vec);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (vec[i][j] == 1 || vec[i][j] == 2) // ���� ģ���̰ų� �Ѵܰ� �ǳ� ģ���� ��� cnt++
				cnt++;
		}
		ans = max(ans, cnt); // �ִ����� ����
	}
	cout << ans << '\n';

	return 0;
}