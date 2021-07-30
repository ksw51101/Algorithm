#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, k, ans;
bool visit[26], flag[26]; // visit : ��� �ܾ �б� ���� ����� �ϴ� ���ڸ� true�� ���� �迭, flag : k���� ���ڸ� ����� �� k���� true�� ���� �迭
vector<string> vec;

// k���� ���ڸ� ��� ���·� �� ���� �ܾ ���� �� �ִ��� return ���ִ� �Լ�
int check() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= vec[i].size(); j++) {
			if (j == vec[i].size())
				cnt++;
			if (!flag[vec[i][j] - 'a'])
				break;
		}
	}
	return cnt;
}

// ����� �ϴ� ���� �� k���� DFS�� �����ϴ� �Լ� (��� ���ں��� ���� index�� ���� ���ڴ� ���캼 �ʿ䰡 �����Ƿ� index ���)
void DFS(int cnt, int index) {
	if (cnt == k) { // k���� ���ڸ� ����� ��� ���� �� �ִ� �ܾ��� �ִ� ans�� ����
		ans = max(ans, check());
		return;
	}
	for (int i = index; i < 26; i++) { // 26���� ���� �� ����� �ϴ� ���ڸ� k�� ����
		if (visit[i] && !flag[i]) { // �ش� index�� ���ڰ� ����� �ϴ� ���ڸ鼭 a, c, i, n, t�� �ƴ� ���
			flag[i] = true;
			DFS(cnt + 1, i + 1);
			flag[i] = false;
		}
	}
}

int main() {
	cin >> n >> k;

	fill(&visit[0], &visit[26], false);
	fill(&flag[0], &flag[26], false);
	flag[0] = flag[2] = flag[8] = flag[13] = flag[19] = true; // ��� �ܾ "anta"�� �����ϰ� "tica"�� �����Ƿ� a, c, i, n, t�� ���� ���

	int cnt = 0; // ��� �ܾ �б� ���� ����� �ϴ� ������ ����
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		vec.push_back(temp);
		for (int j = 0; j < temp.size(); j++)
			if (!visit[temp[j] - 'a']) { // �ܾ �б� ���� �ʿ��� ������ index�� true�� ����
				visit[temp[j] - 'a'] = true;
				cnt++;
			}
	}

	if (cnt <= k) // ��� �ܾ �б� ���� �ʿ��� ������ ������ ��� �� �ִ� ���ڰ� ���� ��� ������ n
		ans = n;
	else if (k < 5) // ��� �ܾ ���� 5���� ���� a, c, i, n, t�� ��� �� ���ٸ� ������ 0
		ans = 0;
	else 
		DFS(5, 0); // DFS ����

	cout << ans << '\n';

	return 0;
}